# BE_Board


Simon GAME

Le jeu a été codé sur simulateur puis pour une intégration réelle.
Le dossier src contient les fichiers source du code sur simulateur.
Le dossier src_integration_reel contient les fichiers source du code prêt à être implémenté sur une carte arduino.

Pour plus d'informations relatives à chacun de ces deux codes, se réferer aux README.md de chacun de ces dossiers

/////////////////////////// But du jeu ///////////////////////////

Fonctionnement : Le programme crée une séquence aléatoire. Le premier joueur doit appuyer sur le bouton Menu. 

Une LED s’allume. Le buzzer émet un son lorsque la séquence d’allumage des LED est terminée (ne fonctionne pas en simulation). 

Lorsque sur l'écran s'affiche "Saisir", c’est alors au joueur d’appuyer sur le bouton poussoir associé à cette LED.
Lorsque le joueur appuie sur un bouton poussoir, la LED associée s’allume. Si le joueur a juste, le jeux continue. 
Sinon on passe au joueur suivant. Pour démarrer sa séquence, le joueur doit appuyer sur Menu.
Au fur et à mesure l’écran LCD affiche le score du joueur (+1 à chaque nouvelle séquence reproduite correctement). 


