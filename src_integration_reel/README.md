# SimonGame
Simon says game with Arduino

/////////////////////////// Composants nécessaires : ////////////////////////////////
	Ecran LCD
	4 LEDs
	5 boutons poussoir (1 pour chaque LED et un pour le choix de niveau)
	Carte arduino uno
	buzzer piézoélectrique 

/////////////////////////// Spécifications branchement //////////////////////////////////
Les numéros des pins sont définis dans le header file Game.h.
Il est possible de les modifier mais il faut que les pin définies soient les mêmes que celles banchées en réel.


/////////////////////////// Cahier des charges (Identique au simulateur) ///////////////////////////

Au démarrage, l’écran LCD affiche un message de démarrage.

Fonctionnement : Le programme crée une séquence aléatoire. Le premier joueur doit appuyer sur le bouton Menu. 

Une LED s’allume. Le buzzer émet un son lorsque la séquence d’allumage des LED est terminée (ne fonctionne pas en simulation). 

Lorsque sur l'écran s'affiche "Saisir", c’est alors au joueur d’appuyer sur le bouton poussoir associé à cette LED.
Lorsque le joueur appuie sur un bouton poussoir, la LED associée s’allume. Si le joueur a juste, le jeux continue. 
Sinon on passe au joueur suivant. Pour démarrer sa séquence, le joueur doit appuyer sur Menu.
Au fur et à mesure l’écran LCD affiche le score du joueur (+1 à chaque nouvelle séquence reproduite correctement). 


/////////////////////////// Création de plusieurs classes : ///////////////////////////

1 classe Device
	1 classe Sensor 
        1 classe Bouton Poussoir
	1 classe Actuator 
	    1 classe LED
	    1 Classe Ecran
	    1 classe buzzer

1 classe joueur

/////////////////////////// Amélioration ///////////////////////////
Le mode multijoueur n'a pas encore été implementé. Les fichiers player.h et 
player.cpp sont encore vide.

Petit soucis du côté de la classe Ecran (LCDscreen) qui présente un soucis
de conversion d'arguments entre la classe LiquidCrystal d'arduino et notre
fonction Display. 
