# Diagramme de Classes
Objectif : Creation d'un visualisatuer SQLLite + Json (pour la gestion des sessions (engistrement des comptes))

## Classes
Classes :

Enum Droits (Utilisateur / Admin ...)
Utilisateur 
 - Identifiant / Nom 
 - Mot de passe
 - Profil (Map <Int, Droits>) //Int c'est 

 - ....

ParseurJson
  - Lecture du fichier Json
  - Ecriture du fichier Json

LecteurSQL (A revoir)
  - Lecture du fichier SQL () 
  - Ecriture du fichier SQL (Pour le nouvel utilisateur (creation du compte) + admin ( modifications des données)
  - 
  

ConnectionView

MainView


## Schéma BDD


Utilisateur(__id__, nom, prenom, motDePasse, profil)

## PUML
  
  ```plantuml
@startuml

package Model {
  enum Droits {
    Lecture
    LectureModification
    LectureModificationEcriture
  }

  abstract class Personne {
    - id: UUID
    - nom: String
  }

  class Utilisateur {
    - profils: Map<String, Droits>
    + droitsParDefaut: Droits

    + changerProfil(nouveauProfil: String): void
    + seConnecter(motDePasse: String): void
    + seDeconnecter(): void
    + supprimerProfil(nomProfil: String): void
    + ajouterProfil(nomProfil: String, droits: Droits): void
    + modifierProfil(nomProfil: String, nouveauxDroits: Droits): void
    + chargerBDD(cheminFichier: String): void
    + modifierBDD(cheminFichier: String): void
  }

  class Administrateur {
    + ajouterProfilUtilisateur(utilisateur: Utilisateur, nomProfil: String, droits: Droits): void
    + supprimerProfilUtilisateur(utilisateur: Utilisateur, nomProfil: String): void
    + modifierProfilUtilisateur(utilisateur: Utilisateur, nomProfil: String, nouveauxDroits: Droits): void
    + ajouterUtilisateur(nom: String, droits: Droits): Utilisateur
    + supprimerUtilisateur(utilisateur: Utilisateur): void
    + modifierUtilisateur(utilisateur: Utilisateur, nouveauxDroits: Droits): void
  }

  class ParseurJson {
    + lireFichierJsonUtilisateur(cheminFichier: String): Utilisateur
    + ecrireFichierJsonUtilisateur(utilisateur: Utilisateur, cheminFichier: String): void
    + lireFichierJsonAdministrateur(cheminFichier: String): Administrateur
    + ecrireFichierJsonAdministrateur(administrateur: Administrateur, cheminFichier: String): void
    + crypterMotDePasse(motDePasse: String): String
    + decrypterMotDePasse(motDePasseCrypte: String): String
  }

  class LecteurSQL {
    + lireFichierSQL(cheminFichier: String): void
    + ecrireFichierSQL(cheminFichier: String): void
  }

  class Modele {
    - utilisateurs: List<Utilisateur>
    - administrateur: Administrateur
    - parseurJson: ParseurJson
    - lecteurSQL: LecteurSQL

    + chargerUtilisateurs(): void
    + sauvegarderUtilisateurs(): void
    + associerUtilisateur(parseurJson: ParseurJson, utilisateur: Utilisateur): void 
    + associerUtilisateur(lecteurSQL: LecteurSQL, utilisateur: Utilisateur): void
    + chargerAdministrateur(): void
    + sauvegarderAdministrateur(): void
    + associerAdministrateur(parseurJson: ParseurJson, administrateur: Administrateur): void
  }
}

package Vue {
  class ConnectionView {
    + afficherPageLogin(): void
    + demanderCreationUtilisateur(): void
    + demanderCreationAdministrateur(): void
  }

  class MainView {
    + afficherPagePrincipale(utilisateur: Utilisateur): void
    + afficherPagePrincipale(administrateur: Administrateur): void
  }
}

package Controleur {
  class Controleur {
    - modele: Model.Modele
    - vueConnection: Vue.ConnectionView
    - vuePrincipale: Vue.MainView

    + demarrerApplication(): void
    + gererConnexionUtilisateur(motDePasse: String): void
    + gererConnexionAdministrateur(motDePasse: String): void
    + gererDeconnexion(): void
  }
}

Model.Personne <|-- Model.Utilisateur
Model.Personne <|-- Model.Administrateur
Model.Utilisateur -- Model.Modele
Model.Administrateur -- Model.Modele
Model.ParseurJson -- Model.Modele
Model.LecteurSQL -- Model.Modele
Vue.ConnectionView -- Controleur.Controleur
Vue.MainView -- Controleur.Controleur
Model.Modele -- Controleur.Controleur

@enduml

```

## Choix 

Nous avons fait le choix de ne pas representer le mot de passe dans la classe Utilisateur, car celui ci ne sera pas "enregistrée", quand on va creer un compte on va l'engistrer dans un fichier Json, et le mot de passe sera crypté, pour se connecter on va utiliser une methode de decrytage pour comparer le mot de passe entré par l'utilisateur avec celui enregistré dans le fichier Json.

Nous avons fait le choix de representer Un Profil comme etant une map on defini ou l'on doit trouver le 