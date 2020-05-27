# BE_Board


Simon GAME


/////////////////////////// Composants nécessaires : ////////////////////////////////
	Ecran LCD
	4 LEDs
	5 boutons poussoir (1 pour chaque LED et un pour le choix de niveau)
	Carte arduino uno
	buzzer piézoélectrique 

/////////////////////////// Cahier des charges : (Simulateur) ///////////////////////////

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
	1 classe Actuator 
	1 classe Bouton Poussoir
	1 classe LED
	1 Classe Ecran
	1 classe buzzer

1 classe joueur

/////////////////////////// Amélioration ///////////////////////////

Lorsqu'on arrive au nombre maximum de joueur, le programme s'arrête. Il faudrait qu'on retourne au premier joueur. 


