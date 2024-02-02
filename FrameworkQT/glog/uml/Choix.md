# Mini Projet

## Choix realisés

### Non presence du mot de passe dans la classe Utilisateur
Nous avons fait le choix de ne pas representer le mot de passe dans la classe Utilisateur, car celui ci ne sera pas "enregistrée", quand on va creer un compte on va l'engistrer dans un fichier Json, et le mot de passe sera crypté, pour se connecter on va utiliser une methode de decrytage pour comparer le mot de passe entré par l'utilisateur avec celui enregistré dans le fichier Json.


### Gestion des droits de façon independante
Nous avons fait le choix de gerer les droits de maniere a ce que l'administauer puisse attribuer l'un des deux droits suivants : 
*Lectures* : Lecture des données
*Lecture/Mofication* : Lecture et modification des données
L'administrateur aura le droit suivant :
*Lecture/Modification/Ecriture* : Lecture, modification et ecriture des données

### CRUD en classe abstraite
On a remarque que les methodes de creation, lecture, modifcation et supression sont les memes que ce soit pour les utilisateur ou les administrateurs, on a donc fait le choix de les mettre dans une classe abstraite, et en fonction des droits de l'utilisateur on va appeler les methodes correspondantes , mais ça nous permet de ne pas dupliquer le code. 

### Choix du format Json
Nous avons fait le choix d'utiliser le format Json pour enregistrer les données.
