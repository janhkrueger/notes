# The Titans Event Timing

Without a doubt the hackiest thing I remember from Titan Quest is how we managed the event scripting. The quest / event tech had a major weakness in that there was no way to delay an action once it was triggered. So if you wanted something to happen 5 seconds after a player ran through some bounding volume, there was no way to set a delay. It would always be instant.

We were nearing the end of production, so it was hard to request additional features, as engineers were slammed just trying to meet their milestone deliverables. One of the QA testers had started helping out with scripting work, and figured out that there was in fact a way to delay an action from triggering based on the length of an animation.

He ended up using these squirrels we had as ambient creatures as the animation timer, and they became the default timing mechanism. He created an invisible version of the squirrel, which he would place in the levels where he needed them, then would time everything based on the duration of their idle animation. Because of his creative problem solving, he was promoted to designer on the next project.
 
- Arthur Bruno

Owner / lead designer, Crate Entertainment

Source: https://www.gamedeveloper.com/programming/developers-share-their-most-memorable-dirty-coding-tricks