<?php
$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('siphash')) {
	dl('siphash.' . PHP_SHLIB_SUFFIX);
}
$module = 'siphash';
$functions = get_extension_funcs($module);
echo "Functions available in the test extension:$br\n";
foreach($functions as $func) {
    echo $func."$br\n";
}
echo "$br\n";
?>
