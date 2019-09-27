# Protocole Babel
**username**: Nom de l'utilisateur, unique et composé de 1 à 32 caractères alphanumériques</br>
**password**: Mot de passe de l'utilisateur, composé de 8 à 32 caractères alphanumériques</br>
**profil_key**: Correspond au différents types d'information sur le profil utilisateur</br>
## Création d'un utilisateur
```
REGISTER <username> <password>
```
#### Réponses:
```
OK Account created
```
```
KO <error>
```

## Connexion
```
LOGIN <username> <password>
```
#### Réponses:
```
OK User logged in
```
```
KO <error>
```

## Obtenir la liste des contacts
```
CONTACT_LIST
```
#### Réponses:
```
OK <username1> <username2>
```
```
KO <error>
```

## Modifier son profil
```
PROFIL_SET <profil_key> <value>
```
#### Réponses:
```
OK <key> updated
```
```
KO <error>
```

## Consulter un profil
```
PROFIL_GET <username> <profil_key>
```
#### Réponses:
```
OK <value>
```
```
KO <error>
```
