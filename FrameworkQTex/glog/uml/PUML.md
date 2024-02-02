# Diagramme de Classes
Objectif : Creation d'un visualisatuer SQLLite + Json (pour la gestion des sessions (engistrement des comptes))

## Classes
Classes :

Enum Droits (Utilisateur / Admin ...)
Utilisateur 
 - Identifiant / Nom 
 - Mot de passe
 - Profil ( Map <String, Droits> )

 - ....

ParseurJson
  - Lecture du fichier Json
  - Ecriture du fichier Json

LecteurSQL (A revoir)
  - Lecture du fichier SQL () 
  - Ecriture du fichier SQL (Pour le nouvel utilisateur (creation du compte) + admin ( modifications des données)
  

ConnectionView

MainView


## Schéma BDD



Utilisateur(__id__, nom, prenom, motDePasse, profil)

## PUML

```plantuml
@startuml Visualisateur 
class 
@enduml
```