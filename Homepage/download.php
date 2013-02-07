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
		<script src="//ajax.googleapis.com/ajax/libs/jquery/1.8.2/jquery.min.js"></script>
		<script src="js/bootstrap.min.js"></script>
		<script type='text/javascript'>
			$(document).ready(function() {
				if ($("[rel=tooltip]").length) {
					$("[rel=tooltip]").tooltip();
				}
			});
		</script>
	</head>

	<body>
		<div class="navbar navbar-inverse navbar-fixed-top">
			<div class="navbar-inner">
				<div class="container">
					<a class="btn btn-navbar" data-toggle="collapse" data-target=".nav-collapse"> <span class="icon-bar"></span> <span class="icon-bar"></span> <span class="icon-bar"></span> </a>
					<a class="brand" href="index.php">SFML-Sidescroller</a>
					<div class="nav-collapse collapse">
						<ul class="nav">
							<li>
								<a href="index.php">Home</a>
							</li>
							<li class="active">
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
				<div class="span6">
					<h1>Install New</h1>
					<p>
						To install SFML-Sidescroller, you have to download the package for your OS. If you are using Windows, you should download the Windows-File, and so on.<br>
If you have the choice, then please use Adfly links to download the game. This would help me a little bit to sponsor this site!
					</p>
					<table class="table">
						<tr>
							<td><a href="http://adf.ly/EYTlK" class="btn btn-large btn-primary">Windows<br>Adfly</a></td>
							<td><a href="http://adf.ly/EYTp2" class="btn btn-large btn-primary">Linux64<br>Adfly</a></td>
							<td><a href="#" rel="tooltip" title="There is no official build yet..." class="btn btn-large btn-primary">Linux32<br>Adfly</a></td>
							<td><a href="#" rel="tooltip" title="There is no official build for foul apples..." class="btn btn-large btn-primary">Mac OSX<br>Adfly</a></td>
						</tr>
						<tr>
							<td><a href="http://maximaximal.com/files/Programming/SFML-Sidescroller/winRelease.zip" class="btn btn-large">Windows</a></td>
							<td><a href="http://maximaximal.com/files/Programming/SFML-Sidescroller/Linux64_newest.tar.gz" class="btn btn-large">Linux64</a></td>
							<td><a href="#" rel="tooltip" title="There is no official build yet..." class="btn btn-large">Linux32</a></td>
							<td><a href="#" rel="tooltip" title="There is no official build for foul apples..." class="btn btn-large">Mac OSX</a></td>
						</tr>
					</table>
				</div>
				<div class="span6">
					<h1>Update Old</h1>
					<p>
						To update your old installation you could, of course, just press the update-button in the game's main-menu. But in case you've completely fucked up your installation, you are always allowed to download a new Version manualy.
						<br>
						Just download the compressed folder for your PC on the left, overwrite your old gamefiles, and enjoy playing!
					</p>
				</div>
			</div>

		</div>
		<!-- /container -->

		<!-- Le javascript
		================================================== -->
		<!-- Placed at the end of the document so the pages load faster -->

		<script src="js/script.js"></script>
	</body>
</html>
