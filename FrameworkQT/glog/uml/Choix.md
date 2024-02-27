# Mini Projet

## Choix realisés

### Non presence du mot de passe dans la classe Utilisateur
Nous avons fait le choix de ne pas representer le mot de passe dans la classe Utilisateur, car celui ci ne sera pas "enregistrée", quand on va creer un compte on va l'engistrer dans un fichier Json, et le mot de passe sera crypté, pour se connecter on va utiliser une methode de decrytage pour comparer le mot de passe entré par l'utilisateur avec celui enregistré dans le fichier Json.


### Gestion des droits de façon independante
Nous avons fait le choix de gerer les droits de maniere a ce que l'administauer puisse attribuer l'un des deux droits suivants : 
*Lectures* : Lecture des données
*Lecture/Mofication* : Lecture et modification des données
L'administrateur aura le droit suivant :
*Lecture/Modification/Ecriture(Suppresion?)* : Lecture, Modification(,Suppresion?) et Ecriture des données


### L'utilisateur ne peut pas creer de compte
On part du principe qur l'administrateur est le seul a pouvoir creer des comptes, et donc l'utilisateur ne peut pas creer de compte ( hormis lors de la premiere utilisation du programme, ou on autorise l'utilisateur a se creer un compte).
Fonctionnement similaire

### Singleton Data
Nous avons fait le choix de faire de la classe Data un singleton, car il est important que les données soient partagées entre les differentes vues, et que l'on puisse acceder a ces données de n'importe ou dans le programme.

### Non utilisation du namespace (Qstring, QMap, ...)
Pour une clarte du code, nous avons fait le choix de ne pas utiliser les namespace, pour que le code soit plus lisible.
De cette maniere on sait exactement d'ou viennent les fonctions et les classes utilisees.

### Choix du format Json
Nous avons fait le choix d'utiliser le format Json pour enregistrer les données. Nous avons utiliser nhlohmann/json pour manipuler les données en format Json.

### Nous avons fait le choix de l'encrytage AES 128
Nous avons fait le choix d'utiliser l'encrytage AES 128 pour crypter les mots de passe, car c'est un encrytage tres utilisé et tres sur, et il est difficile a reaalisé une attaque par force brute dessus.
