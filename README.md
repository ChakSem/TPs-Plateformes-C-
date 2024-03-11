# Utilisation

Un administrateur existe déjà, son Id est *59b1fca3* et son mot de passe est *super_password*.

Au lancement, une interface s'ouvre pour créer un premier utilisateur (qui s'ouvrira chaque fois qu'aucun utilisateur existe).

Les logins peuvent être trouvé dans le fichier *passwords.json* (bien que les mots de passe soit crypté).

# Fonctionnalités supplémentaires

Nous avons ajouté une fonctionnalité qui permet de visualiser le détail de son compte.

# Librairies

Nous avons utilisé 3 librairies : 
- Une pour la géneration d'UUID
- Une pour le cryptage des mot de passe avec la technologie AES
- Une pour le parsing des données dans les fichiers .json

# Documentation et Maquettes

Vous trouverez dans le dossier glog les differentes maquettes et une ebauche du diagramme de classe, ainsi que un fichier Choix.md qui explique certains 

de nos choix que nous avons fait pour la réalisation de ce projet.

// MEMO : regex requete SQL : const regex = /(\s*([\0\b\'\"\n\r\t\%\_\\]*\s*(((select\s+\S.*\s+from\s+\S+)|(insert\s+into\s+\S+)|(update\s+\S+\s+set\s+\S+)|(delete\s+from\s+\S+)|(((drop)|(create)|(alter)|(backup))\s+((table)|(index)|(function)|(PROCEDURE)|(ROUTINE)|(SCHEMA)|(TRIGGER)|(USER)|(VIEW))\s+\S+)|(truncate\s+table\s+\S+)|(exec\s+)|(\/\*)|(--)))(\s*[\;]\s*)*)+)/i;
