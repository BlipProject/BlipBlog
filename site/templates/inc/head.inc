<?php
include("./inc/functions.inc");
/**
 * Demo site header include file (HTML5)
 *
 * Note that this file has nothing to do with ProcessWire. We just split our common 
 * header and footer markup into separate files (head.inc and foot.inc) like this, 
 * since it was common to all of our templates. 
 *
 */

?>
<!DOCTYPE html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7"> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js"> <!--<![endif]-->
 <head>
	<meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
	<title><?php echo $page->get("headline|title"); ?></title>

	<meta name="description" content="<?php echo $page->summary; ?>" />

	<meta name="generator" content="ProcessWire <?php echo $config->version; ?>" />
	<meta name="viewport" content="width=device-width, initial-scale=1">

	<link rel="stylesheet" type="text/css" href="<?php echo $config->urls->templates?>css/bootstrap.min.css" />
	<link rel="stylesheet" type="text/css" href="<?php echo $config->urls->templates?>css/bootstrap-theme.css" />
	<link rel="stylesheet" type="text/css" href="<?php echo $config->urls->templates?>css/main.css" />

	<!--[if IE]>
	<link rel="stylesheet" type="text/css" href="<?php echo $config->urls->templates?>styles/ie.css" />
	<![endif]-->	

	<script type="text/javascript" src="<?php echo $config->urls->templates?>js/vendor/modernizr-2.6.2-respond-1.1.0.min.js"></script>

	<!--
	This website is powered by ProcessWire CMF/CMS.
	ProcessWire is a free open source content management framework licensed under the GNU GPL.
	ProcessWire is Copyright 2012 by Ryan Cramer / Ryan Cramer Design, LLC.
	Learn more about ProcessWire at: http://processwire.com
	-->

</head>
<body>
    <div class="navbar navbar-default navbar-fixed-top" role="navigation">
      <div class="container">
        <div class="navbar-header">
          <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
            <span class="sr-only">Toggle navigation</span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
            <span class="icon-bar"></span>
          </button>
          <a class="navbar-brand" href="<?php echo $config->urls->root; ?>">The Blip Blog</a>
        </div>
        <div class="navbar-collapse collapse navbar-left">
			<?php
			// bundle up the first level pages and prepend the root home page
			$homepage = $pages->get(1);
			$pa = $homepage->children;
			$pa = $pa->prepend($homepage);
			// Set the ball rolling...
			echo renderChildrenOf($pa);	//see inc/functions.inc for credits	
			?>
			<form class="navbar-form navbar-left" role="search" action='<?php echo $config->urls->root?>search/' method='get'>
		        <div class="form-group">
		          <input type="text" class="form-control" placeholder="Search" value='<?php echo htmlentities($input->whitelist('q'), ENT_QUOTES, 'UTF-8'); ?>' />
		        </div>
		        <button type="submit" class="btn btn-default">Submit</button>
	      	</form>			
        </div><!--/.navbar-collapse -->
      </div>
    </div>
   <div class="jumbotron">
    	<div class="container">
			<h1 class="title"><?php 

			// The statement below asks for the page's headline or title. 
			// Separating multiple fields with a pipe "|" returns the first
			// one that has a value. So in this case, we print the headline
			// field if it's there, otherwise we print the title. 
			
			echo $page->get("headline|title"); 

			?></h1>
    	</div>
    </div>
     <div class="container">
		<ol class='breadcrumb'><?php

			// Create breadcrumb navigation by cycling through the current $page's
			// parents in order, linking to each:

			foreach($page->parents as $parent) echo "<li><a href='{$parent->url}'>{$parent->title}</a></li>";
			echo "<li>{$page->title}</li>";
		?></ol>
    </div>
	
	<div class="container">
		<div class="row">
			<div class="sidebar col-md-4 col-md-push-8">
				<?php

				// Output subnavigation
				// 
				// Below we check to see that we're not on the homepage, and that 
				// there are at least one or more pages in this section.
				// 
				// Note $page->rootParent is always the top level section the page is in, 
				// or to word differently: the first parent page that isn't the homepage.

				if($page->path != '/' && $page->rootParent->numChildren > 0) { 

					// We have determined that we're not on the homepage
					// and that this section has child pages, so make navigation: 

					echo "<ul id='subnav' class='nav nav-pills nav-stacked'>";

					foreach($page->rootParent->children as $child) {
						$class = $page === $child ? " class='active'" : '';
						echo "<li$class><a href='{$child->url}'>{$child->title}</a></li>";	
					}

					echo "</ul>";
				}

				?>

				<div class='sidebar_item'>

					<?php

					// if the current page has a populated 'sidebar' field, then print it,
					// otherwise print the sidebar from the homepage
					
					if($page->sidebar) echo $page->sidebar; 
						else echo $homepage->sidebar; 
					?>


				</div>

			</div><!--/sidebar-->
			<div class="content col-md-8 col-md-pull-4">
