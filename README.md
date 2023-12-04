# enseash
Shell created during the System Programming labs

## TP 1

### Question 1:
	Le message de bienvenue fonctionne. Pour l'instant, tout fonctionne comme un simple "hello world".

### Question 2:
	L'exécution des commandes fonctionnes. Pour l'instant, aucun cas de sortie n'est pris en compte et
	le seul moyen de sortir de la boucle est un ctrl c.

	Les erreurs prisent en compte sont actuellement:
		- Erreur de lecture
		- Erreur de création du processus fils
		- Erreur d'exécution de commande

### Question 3:
	Les codes de sorties exit et ctrl + d sont bien fonctionnel de même que le message de sortie.

	Les erreurs prises en compte n'ont pas changé par rapport à la question précédente.

### Question 4:
	Les signaux et code sont bien pris en compte dans l'affichage. Une fonction a été créée pour
	gérer la nouvelle écriture du message prompt.

	Les erreurs prises en compte n'ont pas changé.

### Question 5:
	Le temps est pris en compte. La fonction de la question 4 a été modifié pour en tenir compte.

	Les erreurs prises en compte n'ont pas changé.

### Question 6:
	Les commandes avec arguments sont désormais fonctionnelles. Une fonction permettant de séparer
	la chaîne d'entrée en fonction des espaces a été implémenté et le mode d'exécution a été modi-
	-fié en vectoriel.

	Les erreurs prises en compte n'ont pas changé.

### Question 7:
	Les redirections < et > sont bien pris en compte. Une fonction a été implémentée afin de récu-
	-pérer la fonction et de vérifier si l'un des caractères est un < ou un > et d'agir en fonction
	du résultat.

	Les erreurs prises en compte n'ont pas changé.