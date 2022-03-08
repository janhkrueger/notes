# Git - Pushing code to two repositories

```
git remote set-url --add --push origin git@gitlab.com:janhkrueger/insulae-ci-runner.git
git remote set-url --add --push origin git@github.com:janhkrueger/insulae-ci-runner.git
git remote -v
```


**IMPORTANT NOTE**: Unterschiedliche Hooks können Code in einem Repo annehmen und im anderen ablehnen.
