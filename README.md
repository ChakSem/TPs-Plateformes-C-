# Projet QT

Ce projet consiste en un visualisateur de base de données SQLite.

# Contenu

L'application intègre des profils (_"travail"_ ou _"perso"_ par exemple), qui intègre eux même différentes bases de données, avec un droit sur celles-ci. Chaque utilisateur possède ses profils, et peut donc accéder aux bases de données de ses profils.

Chaque utilisateur a des droits différents :
- Super administrateur : Il existe par défaut un super admin (dont l'id est *59b1fca3* et le mot de passe est *super_password*) qui a tous les droits. Il est unique et ne peut être supprimé.
- Administrateur : Il peut visionner les utilisateurs, les supprimer, en créer de nouveaux et créer des profils.
- Utilisateur : Il peut simplement voir les bases de données de ses profils et éventuellement les modifier si ces droits sur ces profils le lui permettent. Il peut aussi ajouter et supprimer des bases de données à ses profils

Une interface permet la visualisation du contenu des bases de données et la saisie de requêtes (qui ne seront exécutée que si l'utilisateur a les droits).

Les données utilisateurs sont stockées dans des fichiers .json.

# Utilisation

Au lancement, une interface s'ouvre pour créer un premier utilisateur (qui s'ouvrira chaque fois qu'aucun utilisateur existe).

Les logins peuvent être trouvé dans le fichier *passwords.json* (bien que les mots de passe sont cryptés).

# Fonctionnalités supplémentaires

Nous avons ajouté une fonctionnalité qui permet de visualiser le détail de son compte.

# Librairies

Nous avons utilisé 3 librairies : 
- Une pour la génération d'UUID
- Une pour le cryptage des mot de passe avec la technologie AES
- Une pour le parsing des données dans les fichiers .json

# Documentation et Maquettes

Vous trouverez dans le dossier _"FrameworkQT/glog"_ les différentes maquettes et une ébauche du diagramme de classe, ainsi que un fichier Choix.md qui explique certains de nos choix que nous avons fait pour la réalisation de ce projet.


##

_Arthur Crochemore et Alâa Chakori Semmane_
