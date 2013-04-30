## Tommy Saves The Day
This game follows Tommy Trojan as he tries to get to class, running through campus. On his way to class he must avoid the viscious Bruins, 
the overly-caffinated Stanford Trees, angry Sun Devils, flying mascots and DPS out to ruin his day.

----

## Game Objects
#####Tommy Trojan
This object is an image of Tommy Trojan riding Traveler the horse. Since he is the game's main character, he will remain fixed in the 
middle of the screen. The appearance of the horse's movement will be simulated with the use of addittional images that have its legs
in different running positions. The character itself has no power and all he can do is avoid objects as they come at him by jumping or 
by moving left or right.
![alt text] (Images/HORSE_1.png "Tommy Trojan")

#####Bruin Bear
This bear, representing UCLA, will run from the right side of the screen towards Tommy. If Tommy hits it, he will lose health.
![alt text] (Images/BEAR_1.png "Bruin")

#####Stanford Tree
This tree, representing Stanford's mascot, will jump diagonally in and out of Tommy's path. It is Tommy's job to avoid
it by jumping over or by moving left and right.

![alt text] (Images/TREE_1.png "Tree")

#####Arizone Sun Devil
This devil, once it appears, remains stationary but, it shoots fire balls at Tommy.
  * **Fireballs** originate from the Sun Devil and move in a straight line towards Tommy.
  
![alt text] (Images/DEVIL_1.png "Sun Devil")
![alt text] (Images/FIREBALL_1.png "Fireball")
  
#####DPS Officers
DPS originates at the left side of the screen. Since they are riding Segways, and are clearly superior, it is Tommy's job to
jump vertically out of the way as they approach him from behind.

![alt text] (Images/DPS_1.png "DPS")


#####Duck
The Duck (a crude representation of Oregon's mascot) will fly across the top of the game screen at set time intervals. Its sole purpose is
to drop "projectiles" on the main character (Tommy.)
![alt text] (Images/DUCK.png "Duck")


##Gameplay
Gameplay starts when the user presses "Start" from the initial game welcome screen. The spacebar, left and right 
keys will be the only keys used during gameplay. These will be used to move and avoid obstacles.

##Scoring
The game score increases at a constant rate for every second that gameplay continues. It can also be increased by picking up books lying
in the path. 

##Lives
Tommy starts out with 7 lives and each time he hits an obstacle (or gets hit by one from behind) he loses a life. He will die when he runs out
of lives.

##Game Layout
Tommy Trojan (the main character) will remain stationary in the middle of the screen and the other items will move from right to left. The DPS
officer, when he appears, starts from the left and goes right. The game options and status (i.e. Score, Lives, Stop, Start...etc) will be on
a toolbar at the bottom of the screen. The Stop and Start will be PushButtons, the Health indicator a QProgressBar and the score a QLabel. 
![alt text] (Images/GameView.png "Tommy Trojan")

