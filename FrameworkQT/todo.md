- test les requetes
- bouton execute

=> Utiliser la base de donnee test.sqlite que j'ai crée

Fait :
- QString * à QString
- Parser les bases de donnees (lecture) ==> C'est a dire recuperer les tables et les colonnes (A verifier )
- Executer les requetes SELECT (lecture) => Droit LECTURE
- Executer les requetes UPDATE (ecriture) ==> Droit LECTURE_MODIFICATION
- Executer les requetes INSERT (ecriture)=> Droit LECTURE_MODIFICATION
- Executer les requetes DELETE () => Droit LECTURE_MODIFICATION_SUPPRESSION
- parser ecriture (lecture)
- enregistrer l'adresse des bases de donnees pour chaques profil, via des map
- ==> MODIFICATIONS des methodes qu'utilisent profils
- integerer les vues dans le mainWindow (pages)
- Exceptions => supprimer dans les catch
- suppression bdd
- ~~parser profil (lecture)~~
- gerer les controllers
- voir pour qsqldatabase
- initilisation de la vue databasemanagement
- initialisation databasevisualisation
- probleme lorsque meme db ajoute 2 fois
- réparer affichage des table (méthode)

