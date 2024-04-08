# PushSwap

Voici mon premier projet ou l'optimisation était la clé de la réussite, en effet il fallait être capable de trier une liste de 100 000 élément en moins de 15 secondes.

Pour cela j'ai utilisé le radix sort (Tri par base)

En bonus, j'ai rajouté son checker réalisé en haskell !

## Radix Sort

Voici une super explication du site geeksforgeeks:

<img src="/images/radix.png">

## Les règles du PushSwap
Le programme n'est autorisé à travailler qu'avec deux listes, la liste A et la liste B. Tous les nombres sont initialement ajoutés à la liste A et B est vide.

Les actions possible sont:

- pa (push A): Prends le premier élément de B et le met à la première position de A, ne fait rien si B est vide.
- pb (push B): Prends le premier élément de A et le met à la première position de B, ne fait rien si A est vide.
- sa (swap A): Inverse les deux premiers éléments de A, ne fait rien s'il y a 0 ou un seul élément.
- sb (swap B): Inverse les deux premiers éléments de B, ne fait rien s'il y a 0 ou un seul élément.
- ss: Fait sa et sb en même temps.
- ra (rotate A): Décale tous les éléments de A de 1 vers le haut, le premier élément devient donc le dernier.
- rb (rotate B): Décale tous les éléments de B de 1 vers le haut, le premier élément devient donc le dernier.
- rr: Fait ra et rb en même temps.
- rra (reverse rotate A): Décale tous les éléments de A de 1 vers le bas, le dernier élément devient donc le premier.
- rrb (reverse rotate B): Décale tous les éléments de B de 1 vers le bas, le dernier élément devient donc le premier.
- rrr : Fait rra et rrb en même temps.

## Résultat

<img src="/images/result.png">

L'objectif est atteint, tout est fonctionnelle !

## Tester le projet

### Prérequis
    - C
    - Haskell
    - Make

### Lancer le projet

Vous devez modifié le test.nbr pour utilisé le projet

```bash
make
./test.sh
```