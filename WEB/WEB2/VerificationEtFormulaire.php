<!DOCTYPE html>
<html>

<head>
      <title>Vos données</title>
	  <meta charset="utf-8" />
</head>

<body>
<h1>Vérification du formulaire</h1>
<h2>Affichage des données recues</h2>

<?php
  print_r($_POST);
?>
<h2>Rapport d'erreurs</h2>
<ul>
	<li>Sexe:
	<?php 
		if(!isset($_POST["sexe"]))
			echo "absent";
		elseif (($_POST["sexe"]=='f') or ($_POST["sexe"]=='h'))
			echo "OK";
		else
			echo "Différent de f ou h";
	?>
	</li>	
	<li>Nom:
	<?php 
		if(!isset($_POST["nom"]))
			echo "absent";
		elseif (strlen(trim($_POST["nom"])) < 2)
			echo "trop court";
		else
			echo "OK";
	?>
	</li>
	</li>
	<li>Prénom:
	<?php
		if(isset($_POST["prenom"]))
		{
			if(empty($_POST["prenom"]))
				echo "absent";
			elseif (ctype_alpha ($_POST["prenom"]))
				echo "OK";
			else
				echo "contient autre chose que des lettres";
		}
	else	
		echo "absent";		
		
	?>
	</li>
	<li>Pays d'origine:
	<?php
	$pays = array("Allemagne", "Belgique", "Chine", "France", "Maroc", "Tunisie");
	if(isset($_POST["pays"]))
	{
		if (in_array($_POST["pays"], $pays)) 
			echo "Ok" ;
		else
			echo "Pays non valide";
	}
	else
		echo "Absent";
		
	?>
	</li>
	<li>Date de naissance:
	<?php
		if(!isset($_POST["naissance"]))
			echo "absent";
		else
		{  
			$date = date_parse($_POST["naissance"]);
			$jour = $date['day'];
			$mois = $date['month'];
			$annee = $date['year'];
			if(checkdate ( $mois , $jour , $annee )	)
				echo "OK";
			else
				echo "pas ok";
		}	
	?> 
	</li>
	
</body>
</html>
