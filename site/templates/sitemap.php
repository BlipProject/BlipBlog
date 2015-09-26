<?php 

/**
 * Site map template
 *
 */

include("./inc/head.inc"); 

function sitemapListPage($page) {

	echo "<li><a href='{$page->url}'>{$page->title}</a> ";	

	if($page->numChildren) {
		echo "<ul>";
		foreach($page->children as $child) sitemapListPage($child); 
		echo "</ul>";
	}

	echo "</li>";
}

echo "<ul class='sitemap'>";
sitemapListPage($pages->get("/")); 
echo "</ul>";

include("./inc/foot.inc"); 

