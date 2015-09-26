<?php
/*
Navigation for ProcessWire using the Bootstrap 2.2.2 markup
This menu was written by Soma based on work by NetCarver and a bit thrown in by Joss

Navigation Bootstrap 3 update by Damienov, with multi level dropdown support fix
Taken from https://processwire.com/talk/topic/5680-bootstrap-3-navigation-with-multiple-leveltier-fix/
*/

function renderChildrenOf($pa, $output = '', $level = 0)
{
    $output = '';
    $level++;

    foreach ($pa as $child) {
        $atoggle = '';
        $class = '';

        if ($child->numChildren && count($child->parents) == 1) {
            $class .= 'dropdown';
            $atoggle .= ' class="dropdown-toggle" data-toggle="dropdown"';
        } else if ($child->numChildren && count($child->parents) > 1 ) {
            $class .= 'dropdown-submenu';
            $atoggle .= ' class="dropdown-toggle"';
        } else if ($child->numChildren && $child->id != 1) {
            $class .= 'dropdown-menu';
        }

        // Makes the current page and it's top level parent add an active class
        $class .= ($child === wire("page") || $child === wire("page")->rootParent) ? " active" : '';
        $class = strlen($class) ? " class='" . trim($class) . "'" : '';

        if ($child->numChildren && count($child->parents) == 1) {
            // Add Caret if have children
            $output .= "<li$class><a href='$child->url'$atoggle>$child->title <b class='caret'></b></a>";
        } else if ($child->numChildren && count($child->parents) > 1) {
            $output .= "<li$class><a tabindex='-1' href='$child->url'$atoggle>$child->title</a>";
        } else {
            $output .= "<li$class><a href='$child->url'$atoggle>$child->title</a>";
        }

        // If this child is itself a parent and not the root page, then render it's children in their own menu too...
        if ($child->numChildren && $child->id != 1) {
            $output .= renderChildrenOf($child->children, $output, $level);
        }
        $output .= '</li>';
    }
    $outerclass = ($level == 1) ? "nav navbar-nav" : 'dropdown-menu';
    return "<ul class='$outerclass'>$output</ul>";
}
?>