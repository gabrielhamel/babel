# Protocole Babel
**username**: Nom de l'utilisateur, unique et composé de 1 à 32 caractères alphanumériques</br>
**password**: Mot de passe de l'utilisateur, composé de 8 à 32 caractères alphanumériques</br>
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

## Déconnexion
```
LOGOUT
```
#### Réponses:
```
OK User logged out
```
```
KO <error>
```

## Soumettre une invitation
```
INVITE_CONTACT <username>
```
#### Réponses:
```
OK Request done
```
```
KO <error>
```

## Obtenir les invitations en cours
```
GET_INVITE
```
#### Réponses:
```
OK <username1> <username2> ...
```
```
KO <error>
```

## Accepter une invitation
```
ACCEPT_INVITE <username>
```
#### Réponses:
```
OK Invite accepted
```
```
KO <error>
```

## Obtenir sa liste de contacts
```
CONTACT_LIST
```
#### Réponses:
```
OK <username1> <username2> ...
```
```
KO <error>
```
