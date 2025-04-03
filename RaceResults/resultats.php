<?php session_start();

/* try {
	$bdd = new PDO('mysql:host=localhost;dbname=projet_chrono_ng;charset=utf8', 'root', '',
	[PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC]);
} catch(Exception $e) {
	die('Erreur : '.$e->getMessage());
} */

if(!empty($_GET['numCourse'])) {
	$_SESSION['numCourse'] = htmlspecialchars($_GET['numCourse']);
} else {
	$_SESSION['numCourse'] = 1;
}

$tableau_affiche = array("classement", "numero dossard", "nom du coureur",
"prenom du coureur", "horaire de début", "temps intermédiaire", "temps d'arrivée");
?>

<!DOCTYPE HTML>

<html>
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" href="resultats.css">
	</head>
	<body>
		<form method="get" action="resultats.php">
			<select name="numCourse"><?php
				foreach(listeCourse($bdd) as $uneCourse) {
					if($_SESSION['numCourse'] == $uneCourse['id']) {
						echo "<option value=\"" . $uneCourse["id"]
						. "\" selected =\"selected\">" . $uneCourse["nom"] . "</option>";
					} else {
						echo "<option value=\"" . $uneCourse["id"] . "\">"
						. $uneCourse["nom"] . "</option>";
					}
				}
			?></select> <input type="submit" value="sélectionner"/> <br><br>
		</form><br>
		<br><table><?php
			echo "<tr><td>" . implode("</td><td>", $tableau_affiche) . "</td></tr>";
		?></table>
	</body>
</html>

<?php

function listeCourse($bdd) {
	return $bdd->query("SELECT idCourse AS id, nomCourse AS nom FROM course");
}

function tableau($bdd) {
	$preparation = $bdd->prepare("SELECT
	doss.numeroDossard,
	cour.nomCoureur,
	cour.prenomCoureur,
	temps.t_depart,
	temps.t_inter_1 as inter,
	temps.t_arrivee as arrivee
	FROM dossard AS doss
	left join course on (doss.idCourse = course.idCourse)
	left join coureur AS cour on (cour.idCoureur = doss.idCoureur)
	left join chrono AS temps on ((course.idCourse = temps.idCourse)AND(doss.idCoureur = temps.idCoureur))
	WHERE (course.idCourse = ?) ORDER BY temps.t_arrivee");
	
	$preparation->execute(array($_SESSION['numCourse'])); //array($_SESSION['idCourse'])
	return $preparation;
}