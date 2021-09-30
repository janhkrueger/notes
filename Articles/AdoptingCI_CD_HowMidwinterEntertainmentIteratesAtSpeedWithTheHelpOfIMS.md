---
created: 2021-09-29T00:13:05+02:00
modified: 2021-09-29T17:52:52-04:00
---

# Adopting CI/CD: How Midwinter Entertainment iterates at speed with the help of IMS

by ImprobableSeptember 29, 2021

Game development was once like one long sprint: a huge effort until you reached the finish line — at which point you could stop. But with Games as a Service, development happens over several years, not least while the game is live. As you ship new features on a continual basis, the problems and profile of a project will change. Traditional development frameworks are no longer suitable. Using continuous integration/ continuous delivery (CI/ CD) practices is a superior approach, with fast feedback loops that enable the rapid iteration and agile development that allow studios to respond to players and keep them engaged.

But getting there is not straightforward. Tools and processes exist to solve common problems, but they are only part of the solution. Issues related to culture and process are regular blockers to improvement — and these can be unique to the local contexts of each individual studio. However, collaboration can help a studio change its model of working, embrace CI/CD principles, gain the fast feedback loops that unlock meaningful change, and ensure resources are allocated to what really matters.

*"Fast feedback loops unlock meaningful change and ensure resources are allocated to what really matters." - Jafar Soltani, Senior Engineering Manager & Head of Reliability Engineering, Improbable*

## Key principles unlock fast feedback

This is as true for the largest studios as the smallest ones — although for different reasons. Indies and smaller operations can struggle to implement key principles like continuous improvement and learning, working in small increments, sustainable development and fast iteration, purely because it's hard to invest in them — from a time or a financial standpoint. Larger studios tend to have the resources, but in my experience can be prone to blind spots.

Partnership potentially solves for all these things. Smaller game developers can offload shaping and generating the various processes, by bringing in a team to work with them, rather than building one of their own. Larger studios can draw on the resources of those with great expertise in this particular area, in order to help them identify opportunities and gain fresh perspectives.

In all cases, this is about external and internal resources working in concert, to help a studio move at speed, gain faster feedback and improve games more rapidly.

## Transform quality through pipeline optimization

As part of the Improbable Multiplayer Services (IMS) team, I recently worked with Midwinter Entertainment, in an engagement that focused on playtesting to speed up iteration. Integrating changes into Scavengers was slower than Midwinter Entertainment wanted and was hindering fast feedback. Together, we worked on a solution that significantly sped things up, an element of which minimized the validation process for builds from six hours to just two.

*"[Our solution] minimized the validation process for builds from six hours to just two." - Jafar Soltani, Senior Engineering Manager & Head of Reliability Engineering, Improbable*

This kind of optimization can prove transformative. Committed changes can be playtested more rapidly. Blockers can be dealt with by more iterations on the same day. By contrast, if you're waiting six hours for builds, it's unlikely you'll be able to playtest more than once in a single day — if you even get the chance to test the same day at all.

With more frequent playtests, you gain value from people working on the game, through seeing the effect their changes have on it, and others in the studio chipping in feedback as well. Another benefit is improved quality, because regular playtests result in you finding problems sooner rather than later — and you can then respond to them more efficiently and effectively.

## Use tech and people to best effect

With Scavengers now being in Early Access with live players, speed is even more of the essence, because when faced with a blocking issue, it's no longer just about hampering company-wide playtests. It's vital to be able to deal with bugs quickly, to mitigate negative player impact. The processes set up and optimized during the engagement now enable Midwinter Entertainment to release those patches in a matter of hours, instead of days or even weeks.

We also worked with Midwinter Entertainment to do something distinctive, integrating simulated players into the pipeline and game testing. Essentially, they are a framework that allows the game to run with AI/bots, in order to test performance and also stability when performing certain actions.

Scavengers needs 60 players for a full session and end-to-end testing and so the integration of simulated players allowed Midwinter Entertainment to further scale up testing in a big way. We could run tests with 50 simulated players in a session alongside ten humans and get usable and valuable feedback. By offloading to computers what they can do faster, better, more reliably, and repeatedly, it's possible to free up people from repetitive work. So not only does this result in faster, regular, reliable playtests, but also more developers are able to engage in doing things unique to their skillsets.

## Work together to change your studio culture

The nature of this kind of engagement is about bringing expertise from an external team to address problems a studio is having — and to then solve them together. Bringing in outsider consultants that come in, tell people what to do — and then disappear — won't work. This is why we at IMS operate as an enablement team. We keep the customer heavily involved, ideally training studios to understand problems, enabling staff to address and solve similar concerns in future themselves.

*"This kind of engagement is about bringing expertise from an external team to address problems a studio is having — and then solve them together." - Jafar Soltani, Senior Engineering Manager & Head of Reliability Engineering, Improbable*

It's also important to know that tools alone are not enough. There are plenty of tools and techniques at your disposal as you move towards faster iteration: trunk-based development, feature flags, working in small increments, pipeline optimization, parallelization. But fundamentally, this is about principles — creating a cultural shift that enables continuous improvement.

Companies attempt and fail to achieve their goals with tools-first approaches or when attempting to copy someone else's success without fully understanding the uniqueness of individual studios, the benefits of specific tools and processes, and why they are best used. What's important is adopting the right principles.

How can you iterate at speed and get fast feedback? How can you work in small increments and reduce the accumulation of technical debt? How can you continuously improve? Those are the key principles you must strive for.

Source: https://www.gamedeveloper.com/business/adopting-ci-cd-how-midwinter-entertainment-iterates-at-speed-with-the-help-of-ims