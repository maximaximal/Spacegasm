<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="utf-8">
		<title>SFML-Sidescroller</title>
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<meta name="description" content="">
		<meta name="author" content="">

		<!-- Le styles -->
		<link href="css/bootstrap.css" rel="stylesheet">
		<style>
			body {
				padding-top: 60px; /* 60px to make the container go all the way to the bottom of the topbar */
			}
		</style>
		<link href="css/bootstrap-responsive.css" rel="stylesheet">

		<!-- Le HTML5 shim, for IE6-8 support of HTML5 elements -->
		<!--[if lt IE 9]>
		<script src="http://html5shim.googlecode.com/svn/trunk/html5.js"></script>
		<![endif]-->

		<!-- Le fav and touch icons -->
		<link rel="shortcut icon" href="../assets/ico/favicon.ico">
		<link rel="apple-touch-icon-precomposed" sizes="144x144" href="../assets/ico/apple-touch-icon-144-precomposed.png">
		<link rel="apple-touch-icon-precomposed" sizes="114x114" href="../assets/ico/apple-touch-icon-114-precomposed.png">
		<link rel="apple-touch-icon-precomposed" sizes="72x72" href="../assets/ico/apple-touch-icon-72-precomposed.png">
		<link rel="apple-touch-icon-precomposed" href="../assets/ico/apple-touch-icon-57-precomposed.png">
	</head>

	<body>

		<div class="navbar navbar-inverse navbar-fixed-top">
			<div class="navbar-inner">
				<div class="container">
					<a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse"> <span class="icon-bar"></span> <span class="icon-bar"></span> <span class="icon-bar"></span> </a>
					<a class="brand" href="#">SFML-Sidescroller</a>
					<div class="nav-collapse collapse">
						<ul class="nav">
							<li class="active">
								<a href="index.php">Home</a>
							</li>
							<li>
								<a href="download.php">Download</a>
							</li>
							<li>
								<a href="viewScores.php">View Scores</a>
							</li>
						</ul>
					</div><!--/.nav-collapse -->
				</div>
			</div>
		</div>

		<div class="container">
			<div class="row">
				<div class="span8">
					<h1>Sidescroller's Home</h1>
					<h2>What's that?!</h2>
					<p>
						SFML Sidescroller is a sidescrolling-sci-fi-asteroid-space-shoot-them-up-game which throws you asteroids in your face and you have to defend your spaceship from the annoying damage those little bastards can deliver!
						
					</p>
					<h2>But you aren't alone on your endless fight!</h2>
					<p>
						You have the force of half megical half technical powerups on your side! These will give you better lasers (classic), different laser colors (even classier), some extra points (also classic), and one of them has the <strong>amazing</strong> ability to repair your ship!
					</p>
					<h2>What? Highscores?!? Am I in the 90s?</h2>
					<p>
						Maybe, but I don't think they've connected their games to the interwebs in the 90s! You can <strong>upload</strong> your (hopefully) super-hight uber
						highscores to the international scoreboard, so other will have their minds blown up in pieces by your <strong>incredible skillzzzz</strong>! 
					</p>
					<a href="http://sfml-sidescroller.tumblr.com"><h2>News</h2></a>
					<script type="text/javascript" src="http://sfml-sidescroller.tumblr.com/js"></script> 
					<h2><a href="http://imgur.com/a/ABOtb#0">Screenies!!!</a></h2>
					<iframe width="640" height="360" src="http://www.youtube.com/embed/uHD9X6Wf0QM?rel=0" frameborder="0" allowfullscreen></iframe>
					<p>
						<a href="img/Screenshot1.png"><img src="img/Screenshot1.png" alt="Screenshot of the game"></img></a>
						<a href="img/Screenshot9.png"><img src="img/Screenshot9.png" alt="Screenshot of the game"></img></a>
						<a href="img/Screenshot5.png"><img src="img/Screenshot5.png" alt="Screenshot of the game"></img></a>
					</p>
				</div>
				<div class="span4">
					<h1>Last Start</h1>
					<?php echo date("d. m. Y - H:i:s", filectime("../../update/SFML-Sidescroller/lastStart"));
					$handle = fopen("../../update/SFML-Sidescroller/time_played", "r");
					echo "<h1>Time Played</h1>";
					echo (int)(fread($handle, 1000)/60)." minutes";
					fclose($handle);
					?>
				</div>
			</div>
		</div>
		<!-- /container -->

		<!-- Le javascript
		================================================== -->
		<!-- Placed at the end of the document so the pages load faster -->
		<script src="//ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
		<script src="js/bootstrap.min.js"></script>

	</body>
</html>
