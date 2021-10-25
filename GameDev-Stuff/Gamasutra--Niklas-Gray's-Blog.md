# Gamasutra: Niklas Gray's Blog - Physical Design of The Machinery

Created: 2021-10-25 09:41:27 +0200

Modified: 2021-10-25 09:42:26 +0200

---


Physical Design of The Machinery

by [Niklas Gray](http://www.gamasutra.com/blogs/author/NiklasGray/1016727/) on 04/19/17 10:30:00 am 



***The following blog post, unless otherwise noted, was written by a member of Gamasutra's community.***

***The thoughts and opinions expressed are those of the writer and not Gamasutra or its parent company.***





At Our Machinery we have one simple rule that governs the physical design of the code:

**Header files (.h) cannot include other header files**



In other words, header files cannot depend on other header files for the types they need. (Except for <inttypes.h> and <stdboolh.> , we make exceptions for those to get the standard uint32_t and bool types.)

This is a pretty extreme choice. Let's unpack why we made this decision and how we make it work.

**Physical design**

To begin with, if you are not familiar with the term, the *physical design* of a C++ project refers to how the code is broken down into individual .h and .cpp files and how those files are organized on disk --- which files include which others, etc. It is related to, but separate from, the *logical design* which refers to how the components of the system are connected and interact.

Just as with *logical design*, the primary goal of *physical design* is to reduce coupling. We want to minimize the dependencies, so that changes in one file don't have a big impact on other files.

Bad physical design is easy to spot. It happens whenever .cpp files pull in a lot of .h files that they don't need. Most of the time this happens indirectly. The .cpp file includes something it needs. Then that thing includes more stuff. And the stuff includes even more stuff --- completely unrelated to the original problem. Expanding the #includes in such a project can be both scary and enlightening. A few innocent #includes sometimes expand to megabytes of header data once all the recursive inclusion is resolved. This has a number of bad effects:
-   Compiles are slow. (Modern compilers are smart about caching header data, but there are limits to what they can do.)
-   Making changes in single header files causes the whole project to recompile.
-   You sometimes get weird and annoying errors because of name conflicts in the headers you're unwittingly pulling in (#define min in <windows.h> is a classic).

All of these things make it harder and more cumbersome to make code changes, which is the worst thing you can do to a software project. Software needs to be nimble to stay alive. If the code gets too heavy you need an army of programmers to move it along, which is neither efficient nor fun.

A large part of the reason why people are drawn to scripting languages is the ability to iterate over the code quickly, to make changes and immediately see the results. At Our Machinery, we believe the similar things are possible with high-performance static languages, if you just set things up the right way.

**Fixing physical design**

Bad physical design tends to be a creeping issue. In the beginning, when your project is small, compile times are good no matter what, so who cares. When the project gets so big that it starts to be annoying, it is often too late to do anything about it.

Fixing a bad physical design is hard, even if you have [a tool](http://bitsquid.blogspot.se/2011/10/caring-by-sharing-header-hero.html) that can pinpoint where you should focus your efforts. It typically goes something like this:
-   Remove a single #include statement.
-   Insert the forward declarations that might now be needed.
-   Insert new #include statements that might now be needed (because those files were previously included indirectly by the line you just removed).
-   If there are any dependencies that can't be resolved with forward declarations --- refactor the code (this could be an arbitrarily complex task, depending on how gnarly the code is).
-   Make sure the code still compiles.
-   Make sure the code still compiles *on every supported platform and in every supported configuration*.
-   If you had to refactor the code, run tests to make sure you didn't introduce any new bugs.

That's a lot of work to remove one single #include statement. And of course, removing a single #include doesn't have any measurable effect on the compile time or anything else that people care about. You have to repeat this, again and again, hundreds, maybe thousands of times before you start seeing results. It's thankless, unrewarding grunt work. And if the physical design is already bad, all those compiles you need to do to check if things still work will take a really long time.

Also, while you are slaving away at this, the rest of the team is doing some other work, happily adding new #include statements everywhere. There is a reasonable chance that over the next few months, all the work you just did will be undone.

Physical design is really easy to screw up, but requires concentrated effort and hard work to fix. This means that time and human nature will pretty much guarantee that you are screwed. It's simple thermodynamics.

So in a lot of large codebases, people essentially just give up and switch to [unity builds](https://en.wikipedia.org/wiki/Single_Compilation_Unit) or something. Once you are in that hole, it might even be the right decision, but that's not where we want to end up with Our Machinery.

**Necessity is the mother of prevention**

Since the problem is so hard to fix, we need to stop it before it happens. We need rules that people can follow to avoid getting into this mess. But if you look online, most of the rules you find will boil down to something like:

Don't include more header files than you need

That is good *advice*, but it as a rule it sucks. It's too vague. It doesn't tell you what to do or how to solve problems you encounter. It's not verifiable. A rule like that will not stop people from just adding #includes until the code compiles. After all, that's what they "need". We have:

Vague rules + no enforcement + path of least resistance + human nature → chaos

Rules should be clear enough that it is obvious if the code follows them or not. Even better, they should be machine verifiable. That way, we can just put the rule in the pre-commit hook and be *certain* that it is always followed.

This is why we use clang-format to format our code. It doesn't do exactly what we want, but it is close enough that having automatic formatting is worth the trade-off.

(If you want to know --- our main gripe with clang-format is that it insists on left flushing pre-processor directives instead of indenting them with the rest of the code. I find this a terrible, unreadable practice --- especially when you have nested levels of #ifs and #elses . Maybe we'll make a patch for it some day, unless someone beats us to the punch.)

**Cutting the Gordian knot**

All that exposition explains why we went with a simple, unambigous and easy to remember rule:

**Header files (.h) cannot include other header files** (except for <inttypes.h> and <stdbool.h>)

This rule is simple and clear enough to be machine verifiable and it completely solves the problem of physical design.

Note: Even with this rule we can still have .cpp files that include headers they don't need, but that's not really a big problem. If we eliminate headers including other headers we don't get the big expanding tree of includes --- everything stays pretty contained. And it's easy to remove #includes in a single .cpp file and check if that file still compiles --- we don't have to touch or compile any other part of the project. In fact, it is so easy that we can automate the process.

Not allowing *any* header file inclusions is a drastic choice, but that is also what I like about it. I think a lot can be learned by picking an interesting idea or philosophy and see just how far we can push it. Even if we don't make it all the way we will learn a lot of new things by trying.

But does the rule work in practice? Can we actually write header files that don't depend on types defined in other header files? Let's look some of the problems you encounter when trying to do that and how we deal with them.

**Classes**

Classes are tricky. If you write your classes following a strict [PIMPL idiom](https://en.wikipedia.org/wiki/Opaque_pointer) and only put abstract interfaces in the headers you might be able to get away with just forward declarations. But that is kind of a complicated way to write C++. And as soon as you want concrete classes, inheritance, templates or inline functions you start to get into trouble.

Our solution to this is simple --- we don't use classes. Our header files are written in plain old C, C99 to be precise. The *implementation* files can be either C or C++ --- whatever makes sense for that particular piece of code --- but the APIs and interfaces are strict C. We have several good reasons for this approach, which I will detail in a future blog post, but the main one is that it gives us better logical decoupling. And presto, we get better physical decoupling too, as we don't need to worry about class dependencies in the header files.

**Templates**

One of the reasons why we allow C++ in the implementation files is that templates are a very convenient way of solving certain programming problems. But how can we use templates without having headers include other headers?

First, the templates are only used in the .cpp files. Thus, the .h files never need to include them. Second, the templates themselves are written in .inl files rather than .h files, and we don't have any rule against .inl files including other .inl files. In other words, you can write a template that depends on another template.

This may seem like just semantic trickery --- if we allow .inl file to include .inl files aren't we just recreating the whole rat's nest again, just with .inl files instead of .h files?

Actually, I don't think so. We use .inl files very sparingly --- only for template code. We're in general very conservative about using "advanced C++" features and not at all into template-metaprogramming with trait classes, etc. But templates are convenient for things like arrays and hashes. In fact, we currently have exactly two .inl files in the project --- array.inl and hash.inl . Granted, the project is still small, but we don't expect to add many more.

**Inlined functions**

What about inlined functions then? Don't we want to use inlined functions in our header files to improve performance? And in that case, don't we want to allow headers to include other headers, so that one inlined function can call another and have all those calls optimized away?

Not really. Inline functions are a C++ solution to a C++ problem. "Good C++ design" encourages having many layers of abstraction with simple functions doing trivial things. Then it promises that through inlined functions and optimizing compilers, all those levels of abstraction will be cost-free, since everything will compile down to a few simple assembly instructions. And it actually works most of the time.

But we question the benefits of all those abstraction layers in the first place. As anyone who has tried to step into STL code in the debugger knows, adding abstraction layers does not necessarily make the code easier to understand. On the contrary it can sometimes make you feel lost in a maze, wondering where *the real code* is. What is the benefit of abstraction if it doesn't help programmers?

Sure, if you have an interface function Vector3::get_x() , then that function better be inlined, because otherwise you are paying a heavy price for just retrieving a float. But we prefer to write meatier methods in the APIs, that operate on more than one item at a time. For example, instead of get_x(), maybe we have a function for getting the positions of all objects:

// Retrieves pointers to the arrays of x, y and z positions and returns

// the total number of items in those arrays.

uint32_t get_positions(float **x, float **y, float **z);

This is a part of our [data-oriented design](https://en.wikipedia.org/wiki/Data-oriented_design) philosophy: where there is one, there are many.

With "meatier" functions in the API we don't have to worry about the function call overhead, because we won't be calling them a million times. Another interesting thing to note is that while we have to pay the cost of the functional call, this API style makes much more important optimizations possible. For example, with direct access to the coordinate arrays, we can write our processing code using SIMD instructions and gain an immediate 4x speed boost.

**OS types**

What about OS types then, such as HANDLE , don't we need to include <windows.h> in order to deal with them?

In our API, we represent all OS types as opaque collections of bits:

struct tm_file_t {uint64_t opaque;};

Then in the implementation files we just memcpy() our HANDLE , or whatever the type is for a particular OS, in and out of the tm_file_t . We make sure to make the tm_file_t structure "big enough" to fit the file handle type in all our supported OSes.

**Conclusion**

So far, our decision not to allow header files to include other header files has been a great one. Not only has it kept compile times and dependencies down, but we have also found that the strictness that it imposes on the physical design tends to make the logical design clearer and simpler.

We haven't yet encountered a situation where this approach has led to trouble. We will continue to use it and try to take it all the way to the finished product.
