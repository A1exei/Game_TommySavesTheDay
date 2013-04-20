## Tommy Saves The Day
This game follows Tommy Trojan as he tries to get to class before the time runs out. On his way to class he must avoid the viscious Bruins, 
the overly-caffinated Stanford Trees, angry Sun Devils, construction obstacles and DPS officers that dont move for anyone.

----

## Game Objects
#####Tommy Trojan
This object is an image of Tommy Trojan riding Traveler the horse. Since he is the game's main character, he will remain fixed in the 
middle of the screen. The appearance of the horse's movement will be simulated with the use of addittional images that have its legs
in different running positions. The character itself has no power and all he can do is avoid objects as they come at him by jumping.
![alt text] (Pic1.jpg "Tommy Trojan")

#####Bruin Bear
This bear, representing UCLA, will run from the right side of the screen towards Tommy. If Tommy hits it, he will lose health.
![alt text] (Bear.gif "Bruin")

#####Stanford Tree
This tree, representing Stanford's mascot, will appear to pace back and forth once it appears in Tommy's path. It is Tommy's job to avoid
it by jumping over.

![alt text] (Tree.jpg "Tree")

#####Arizone Sun Devil
This devil, once it appears, remains stationary but, it shoots fire balls at Tommy.
  * **Fireballs** originate from the Sun Devil and move in a straight line towards Tommy.
  
![alt text] (SunDevil.gif "Sun Devil")
  
#####DPS Officers
DPS originates at the left side of the screen. Since they are riding Segways, and are clearly superior, it is Tommy's job to
jump vertically out of the way as they approach him from behind.

![alt text] (DPS_Segway.jpg "DPS")


#####Books
These are lying stationary along Tommy's path and can be picked up by Tommy as he moves over them. Collecting them helps to increase the
user's score.

#####Construction Obstacles
These stationary obstacles represent the perpetual state of construction on campus and must be jumped over.

#####First Aid
First Aid crosses can be picked up by Tommy along the way to increase his current health by 1 life.


##Gameplay
Gameplay starts when the user presses "Enter" from the initial game welcome screen. The only controls used in gameplay will be
the spacebar which allows Tommy to jump to avoid osbtacles.

##Scoring
The game score increases at a constant rate for every 10 seconds that gameplay continues. It can also be increased by picking up books lying
in the path. 

##Lives
Tommy starts out with 7 lives and each time he hits an obstacle (or gets hit by one from behind) he loses a life. He will die when he runs out
of lives.

##Game Layout
Tommy Trojan (the main character) will remain stationary in the middle of the screen and the other items will move from right to left. The DPS
officer, when he appears, starts from the left and goes right. The game options and status (i.e. Score, Lives, Stop, Start...etc) will be on
a toolbar at the top of the screen. The Stop and Start will be PushButtons, the Health indicator a QListWidget and the score a QLabel. The 
spacebar will be the only key used during gameplay, with the exception of the "esc" key which will exit the game at any time.
![alt text] (GameView.png "Tommy Trojan")
