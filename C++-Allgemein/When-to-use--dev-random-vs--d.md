# When to use /dev/random vs /dev/urandom

Created: 2021-10-25 09:36:31 +0200

Modified: 2021-10-25 09:36:35 +0200

---


Use/dev/urandomfor most practical purposes.

The longer answer depends on the flavour of Unix that you're running.



[Historically,/dev/randomand/dev/urandomwere both introduced at the same time.](https://unix.stackexchange.com/q/323610/143394)



As @DavidSchwartz pointed out[in a comment](https://unix.stackexchange.com/q/323610/143394), using/dev/urandomis preferred in the vast majority of cases. He and others also provided a link to the excellent[Myths about/dev/urandom](http://www.2uo.de/myths-about-urandom/)article which I recommend for further reading.



In summary:
-   The[manpage](http://man7.org/linux/man-pages/man4/random.4.html)is misleading
-   Both are fed by the*same*[CSPRNG](https://en.wikipedia.org/wiki/Cryptographically_secure_pseudorandom_number_generator)to generate randomness ([diagrams 2 and 3](http://www.2uo.de/myths-about-urandom/))
-   /dev/randomblocks when it runs out of entropy
-   The amount of entropy is conservatively estimated, but not counted
-   /dev/urandomwill never block, reading from/dev/randomcan halt processes execution.
-   In rare cases very shortly after boot, the[CSPRNG](https://en.wikipedia.org/wiki/Cryptographically_secure_pseudorandom_number_generator)may not have had enough entropy to be properly seeded and/dev/urandommay not produce high-quality randomness.
-   Entropy running low is not a problem if the CSPRNG was initially seeded properly
-   The CSPRNG is being constantly re-seeded
-   In Linux 4.8 and onward,/dev/urandomdoes not deplete the entropy pool (used by/dev/random) but uses the CSPRNG output from upstream.
-   Use/dev/urandom.



**Exceptions to the rule**

In the Cryptography Stack Exchange's[When to use/dev/randomover/dev/urandomin Linux](https://crypto.stackexchange.com/q/41595/40609)@otus[gives two use cases](https://crypto.stackexchange.com/a/41596/40609):

1.  Shortly after boot on a low entropy device, if enough entropy has not yet been generated to properly seed/dev/urandom.

```{=html}
<!-- -->
```
2.  [Generating a one-time pad with information theoretic security](https://crypto.stackexchange.com/q/35031/40609)

If you're worried about (1), you can[check the entropy available in/dev/random](https://serverfault.com/q/529750/322507).

If you're doing (2) you'll know it already :)

Note: You can[check if reading from /dev/random will block](https://unix.stackexchange.com/q/243127/143394), but beware of possible race conditions.



**Alternative: use neither!**

@otus also pointed out that the[getrandom()](http://man7.org/linux/man-pages/man2/getrandom.2.html)system will read from/dev/urandomand only block if the initial seed entropy is unavailable.

There are[issues with changing/dev/urandomto usegetrandom()](https://lkml.org/lkml/2016/10/21/982), but it is conceivable that a new/dev/xrandomdevice is created based upongetrandom().



macOS

It does't matter, as[Wikipedia says](https://en.wikipedia.org/wiki/dev/random#macOS_and_iOS):

macOS uses 160-bit[Yarrow](https://en.wikipedia.org/wiki/Yarrow_algorithm)based on SHA1. There is no difference between /dev/random and /dev/urandom; both behave identically. Apple's iOS also uses Yarrow.



FreeBSD

It does't matter, as[Wikipedia says](https://en.wikipedia.org/wiki/dev/random#FreeBSD):

/dev/urandomis just a link to/dev/randomand only blocks until properly seeded.

This means that after boot, FreeBSD is smart enough to wait until enough seed entropy has been gathered before delivering a never-ending stream of random goodness.



NetBSD

Use/dev/urandom, assuming your system has read at least once from/dev/randomto ensure proper initial seeding.

The[rnd(4) manpage says](https://www.netbsd.org/~riastradh/tmp/20141116/rnd.html):

/dev/urandomNever blocks.

/dev/randomSometimes blocks. Will block early at boot if the system's state is known to be predictable.

Applications should read from /dev/urandom when they need randomly generated data, e.g. cryptographic keys or seeds for simulations.

Systems should be engineered to judiciously read at least once from /dev/random at boot before running any services that talk to the internet or otherwise require cryptography, in order to avoid generating keys predictably.



Aus < <https://unix.stackexchange.com/questions/324209/when-to-use-dev-random-vs-dev-urandom>>

Use/dev/urandomfor most practical purposes.

The longer answer depends on the flavour of Unix that you're running.

Linux

[Historically,/dev/randomand/dev/urandomwere both introduced at the same time.](https://unix.stackexchange.com/q/323610/143394)

As @DavidSchwartz pointed out[in a comment](https://unix.stackexchange.com/q/323610/143394), using/dev/urandomis preferred in the vast majority of cases. He and others also provided a link to the excellent[Myths about/dev/urandom](http://www.2uo.de/myths-about-urandom/)article which I recommend for further reading.

In summary:
-   The[manpage](http://man7.org/linux/man-pages/man4/random.4.html)is misleading
-   Both are fed by the*same*[CSPRNG](https://en.wikipedia.org/wiki/Cryptographically_secure_pseudorandom_number_generator)to generate randomness ([diagrams 2 and 3](http://www.2uo.de/myths-about-urandom/))
-   /dev/randomblocks when it runs out of entropy
-   The amount of entropy is conservatively estimated, but not counted
-   /dev/urandomwill never block, reading from/dev/randomcan halt processes execution.
-   In rare cases very shortly after boot, the[CSPRNG](https://en.wikipedia.org/wiki/Cryptographically_secure_pseudorandom_number_generator)may not have had enough entropy to be properly seeded and/dev/urandommay not produce high-quality randomness.
-   Entropy running low is not a problem if the CSPRNG was initially seeded properly
-   The CSPRNG is being constantly re-seeded
-   In Linux 4.8 and onward,/dev/urandomdoes not deplete the entropy pool (used by/dev/random) but uses the CSPRNG output from upstream.
-   Use/dev/urandom.

**Exceptions to the rule**

In the Cryptography Stack Exchange's[When to use/dev/randomover/dev/urandomin Linux](https://crypto.stackexchange.com/q/41595/40609)@otus[gives two use cases](https://crypto.stackexchange.com/a/41596/40609):

1.  Shortly after boot on a low entropy device, if enough entropy has not yet been generated to properly seed/dev/urandom.

```{=html}
<!-- -->
```
2.  [Generating a one-time pad with information theoretic security](https://crypto.stackexchange.com/q/35031/40609)

If you're worried about (1), you can[check the entropy available in/dev/random](https://serverfault.com/q/529750/322507).

If you're doing (2) you'll know it already :)

Note: You can[check if reading from /dev/random will block](https://unix.stackexchange.com/q/243127/143394), but beware of possible race conditions.

**Alternative: use neither!**

@otus also pointed out that the[getrandom()](http://man7.org/linux/man-pages/man2/getrandom.2.html)system will read from/dev/urandomand only block if the initial seed entropy is unavailable.

There are[issues with changing/dev/urandomto usegetrandom()](https://lkml.org/lkml/2016/10/21/982), but it is conceivable that a new/dev/xrandomdevice is created based upongetrandom().

macOS

It does't matter, as[Wikipedia says](https://en.wikipedia.org/wiki/dev/random#macOS_and_iOS):

macOS uses 160-bit[Yarrow](https://en.wikipedia.org/wiki/Yarrow_algorithm)based on SHA1. There is no difference between /dev/random and /dev/urandom; both behave identically. Apple's iOS also uses Yarrow.

FreeBSD

It does't matter, as[Wikipedia says](https://en.wikipedia.org/wiki/dev/random#FreeBSD):

/dev/urandomis just a link to/dev/randomand only blocks until properly seeded.

This means that after boot, FreeBSD is smart enough to wait until enough seed entropy has been gathered before delivering a never-ending stream of random goodness.

NetBSD

Use/dev/urandom, assuming your system has read at least once from/dev/randomto ensure proper initial seeding.

The[rnd(4) manpage says](https://www.netbsd.org/~riastradh/tmp/20141116/rnd.html):

/dev/urandomNever blocks.

/dev/randomSometimes blocks. Will block early at boot if the system's state is known to be predictable.

Applications should read from /dev/urandom when they need randomly generated data, e.g. cryptographic keys or seeds for simulations.

Systems should be engineered to judiciously read at least once from /dev/random at boot before running any services that talk to the internet or otherwise require cryptography, in order to avoid generating keys predictably.



Aus < <https://unix.stackexchange.com/questions/324209/when-to-use-dev-random-vs-dev-urandom>>
