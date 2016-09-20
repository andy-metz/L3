<?php  // Vérification

$message_erreur = array();
if(isset($_POST["submit"]))
{	// test sur le sexe
	$message_erreur["sexe"] = "";
	if(!isset($_POST["sexe"]))
		$message_erreur["sexe"] = "absent";
	elseif (($_POST["sexe"]=='f') or ($_POST["sexe"]=='h'))
		$message_erreur["sexe"] =  "OK";
	else
		$message_erreur["sexe"] = "Différent de f ou h";
	
	
}
?>
<!DOCTYPE html>
<html>

<head>
      <title>Vérification formulaire</title>
	  <meta charset="utf-8" />
</head>

<body>

<h1>Vos données</h1>

<form method="post" action=# >
<fieldset>
    <legend>Informations personnelles</legend>
	Vous êtes :  
	<input type="radio" name="sexe" value="f"  <?php if(isset($_POST["sexe"])) if($_POST["sexe"] == 'f' )echo "checked" ?>/> une femme 	
	<input type="radio" name="sexe" value="h"  <?php if(isset($_POST["sexe"])) if($_POST["sexe"] == 'h' )echo "checked" ?>/> un homme
	<br />
    Nom :    
	<input type="text" name="nom" required="required" value="<?php if(isset($_POST["nom"])) echo $_POST["nom"] ?>" /><br />   
    Prénom : 
	<input type="text" name="prenom" value="<?php if(isset($_POST["prenom"])) echo $_POST["prenom"] ?>"/><br /> 	
    Date de naissance : 
	<input type="date" name="naissance" value="<?php if(isset($_POST["naissance"])){list($annee, $mois, $jour) = explode('-', $_POST["naissance"]); echo $jour."//".$mois."//".$annee;}  ?>"/><br />;
	Pays d'origine :
    <input name="pays" list="pays" />
	<datalist id="pays">
		<option value="Allemagne" />
		<option value="Belgique" />
		<option value="Chine" />
		<option value="France" />
		<option value="Maroc" />
		<option value="Tunisie" />
	</datalist> 	
	
</fieldset>


	<br />
<input type="submit" value="Valider" name="submit" />
         
</form>
<?php
  echo print_r($_POST);
	foreach($message_erreur as $erreur => $valeur)
		if($valeur != "OK")
			echo $erreur.": ".$valeur;
		
?>	
</body>
</html>
