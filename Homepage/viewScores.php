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
					<a class="brand" href="#">SFML-Sidescroller</a>
					<div class="nav-collapse collapse">
						<ul class="nav">
							<li>
								<a href="index.php">Home</a>
							</li>
							<li>
								<a href="download.php">Download</a>
							</li>
							<li class="active">
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
					<h1>Official Score List</h1>
					<table class="table table-condensed">
						<thead> 
							<tr>
								<th>Rank</th>
								<th>Score</th>
								<th>Name</th>
								<th>Version</th>
								<th>Time</th>
							</tr>
						</thead>
						<tbody>
							<?php
							$handle = fopen("../../update/SFML-Sidescroller/scores.csv", "r");
							$file = fread($handle, filesize("../../update/SFML-Sidescroller/scores.csv"));
							fclose($handle);
							$Entrys = explode("|", $file);
							//Output Score
							$i = 1;
							foreach($Entrys as $Entry)
							{
								echo "<tr>\n";
								$Entry = str_replace("\n", "", $Entry);
								$Values = explode(";", $Entry);
								if($Values[2] != "")
								{
									$Score = $Values[0];
									$Author = $Values[1];
									$Time = $Values[2];
									$Version = $Values[3];
									echo "<td>";
										echo $i.".";
									echo "</td>";
									echo "<td>";
										echo $Score;
									echo "</td>";
									echo "<td>";
										echo $Author;
									echo "</td>";
									echo "<td>";
										echo $Version;
									echo "</td>";
									echo "<td>";
										echo date("d.m.y - H:i:s", $Time);
									echo "</td>";
									$i = $i + 1;
								}
								echo "</tr>\n";
							}
							?>
						</tbody>
					</table>
				</div>
				<div class="span4">
					<h1>About</h1>
					<p>
						Those scores are loaded from the central score server at <a href="#" rel="tooltip" title="Our main application update & sync server.">update.srcttp.org</a>.
						<br><br>
						You can only upload your score through your <a href="download.php">own copy</a> of SFML-Sidescroller!
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
