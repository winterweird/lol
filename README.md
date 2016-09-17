# lol

Have you ever thought about how "lol" kind of looks like a top-down view zombie approaching your last message with an intent to kill? ... Never? Well, I have. And I realized that I could make that into a game, so here ya go, GitHub! This is what my brain was able to produce today.

### Setting

The world is a post-apocalyptic nightmare. It all began with one infected person, and, through the power of vague plot progression, escalated into a horrific dystopia where everyday is a battle for survival and a gun is man's best friend. A small group of survivors have gathered, you among them. Sadly, due to the collapse of civilization, food and water is sparse and disease is common. Among the survivors, you alone are fit to fight.

Suddenly, you see a lone zombie crest the hill. It looks about, then tilts its head back and sniffs the air. Then it releases a feral cry that sends shivers down your spine and makes you wonder how that thing could ever have been human. Shortly its friends arrive, and in what seems like seconds, the hill is positively teeming with them. They start advancing towards you, arms lifted threateningly in front of them. For an instance, you consider fleeing, but you simply can't abandon the other refugees. You grab your gun, all too conscious about the shortage of ammunition, and vow to sell your life dearly.

On impulse, you bring out your one remaining personal belonging not essential to survival. A brazen lamp, one that had been a prized possession of your grandfather. You two had been so close, before he... He deserved a better ending than that. You softly caress the metal, wishing that you could hear his comforting voice one more time...

Suddenly everything is wrapped in white smoke, and you hear a voice booming: "Who art thou, who disturbeth my slumber?"

Out of the lamp seeps a gaseous substance which solidifies into the shape of a man. It's a genie!

The genie explains to you that you will get three wishes, but he insistently asks that you use your final wish to set him free from the wretched lamp. If you don't, since mankind is surely coming to an end, he will be trapped there forever. You impatiently nod, watching the zombies approach slowly but surely.

Life essentials come first, of course. Your first wish is for an abundance of food and drinking water for your refugee camp, and the genie fulfills it with a flick of his finger. Then, bearing all the sick people in the camp, you wish for medical supplies to help treat them, which the genie grants also.

However, this does not solve one of your most urgent problems, and now there is only one wish left! The genie looks at you expectantly, but you suddenly realize that you will need this wish for yourself as well. You could wish the zombies gone, but... That would not solve your problems of ammunition, and in this kind of world, you realize that a gun will come in handy, even be necessary, for survival.

Then a brilliant idea springs to mind. "Genie, for my last wish, I want to never be out of bullets!" you exclaim triumphantly. The genie's face turns ashen, but he is still bound by the lamp and has to honor your word. A curse gets cut off as he dissipates, being sucked back into the lamp, which then wrestles itself free of your grasp and floats away into the horizon.

But it seems the genie had found some wriggle room in his obligation to heed your final wish. It seems that he interpreted "never be out of bullets" to mean "make one bullet last forever". This means that every time you fire your gun, the bullet gets magically transported back from its previous location. That means you absolutely cannot fire the gun again before the bullet has reached its target!

Cursing under your breath, you lift the barrel. You'll make do somehow.

### Screenshots

![Screenshot 1](https://i.gyazo.com/0eae23d68fb3e5b35328eb082241532c.png)

![Screenshot 2](https://i.gyazo.com/f2a2164690c2347e6e67bfc7b8331f4c.gif)

### How to play

You move left and right with the A and D keys, and fire your gun with the spacebar. The bullets have a maximum reach of not very far, and also a constant velocity of not very fast. And remember that you only have one bullet. Like, at all times. Good luck!

### Caveats

This is a Windows-only program. It has been confirmed to compile and work using MinGW (5.3.0, I think), but I don't know if it'll work when compiled on a different computer. It probably won't run properly in Wine. The binaries in the bin folder were built on a 64 bit Windows computer. I cannot guarantee that they'll work on anyone else's.

Also, the program expects the user's command prompt to be 80 characters wide and 25 characters tall. I'm pretty sure the output will end up looking strange if it's either narrower or taller than that. By that, I mean that if it's narrower, the output will probably wrap around, and if it's taller, the zombies will pop into existence in the middle of the screen. I'm also pretty sure that if you make the window less tall than 25 characters, you'll have to wait a little bit for the first zombies to appear.

### TODO list (arranged in order of decreasing priority)

- [ ] Create a menu to select between gameplay, instructions, credits, story, etc.
- [ ] Tweak the way the spawn rate and the speed of the zombies increases as a function of the score for a better difficulty progression
- [ ] Add randomly appearing power-ups and power-downs which are activated if your bullet hits them
- [ ] Incorporate a health parameter in the zombies and let their HP increase with the difficulty
- [ ] Add difficulty settings
- [ ] Add more sophisticated enemies as a part of the difficulty progression
- [ ] Make millions off this brilliant game concept
- [ ] Port this project to Unix-like platforms

### Known bugs/issues

* Sometimes a bullet glitches through a zombie, and you almost certainly die. I'm not fixing that.
* The source code uses non-standard Windows-functions such as getch (_getch in MSVC), and the Win32 API. It's probably possible to translate all of it to work on Unix-like systems, but I'm putting that on hold indefinitely.
* This code is a fucking mess. Sorry.

### Unknown bugs/issues

* I have no clue whether this will even compile on anyone else's computer.
* For some reason the "ill_advised_update" executable in the bin folder told me it needed permissions to change stuff on my computer when I tried running it earlier. I have no idea why. It's probably not a virus.
