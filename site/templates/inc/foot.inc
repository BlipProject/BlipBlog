			<?php 

			// Output navigation for any children below the bodycopy.
			// This navigation cycles through the page's children and prints
			// a link and summary: 

			if($page->numChildren) {

				echo "<ul class='nav'>";

				foreach($page->children as $child) {
					echo "<li><p><a href='{$child->url}'>{$child->title}</a><br /><span class='summary'>{$child->summary}</span></p></li>"; 
				}

				echo "</ul>";
			}

			?>
			</div><!--/content-->
		</div><!--/row-->
	</div><!--/container-->

	<div id="footer" class="footer jumbotron">
		<div class="container">
			<p>Powered by <a href='http://processwire.com'>ProcessWire Open Source CMS/CMF</a> &copy; <?php echo date("Y"); ?> <a href="http://www.ryancramer.com">Ryan Cramer Design, LLC</a></p>
		</div>
	</div>

		<?php 

		// If the page is editable, then output a link that takes us straight to the page edit screen:
		if($page->editable()) {
			echo "<a class='btn btn-default pull-right' id='editpage' href='{$config->urls->admin}page/edit/?id={$page->id}'>Edit</a>"; 
		}

		?>
	<script src="//ajax.googleapis.com/ajax/libs/jquery/1.11.0/jquery.min.js"></script>
    <script>window.jQuery || document.write('<script src="<?php echo $config->urls->templates?>js/vendor/jquery-1.11.0.min.js"><\/script>')</script>
    <script src="<?php echo $config->urls->templates?>js/vendor/bootstrap.min.js"></script>
    <script src="<?php echo $config->urls->templates?>js/main.js"></script>
</body>
</html>
