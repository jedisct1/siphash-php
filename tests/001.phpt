--TEST--
Check for siphash presence
--SKIPIF--
<?php if (!extension_loaded("siphash")) print "skip"; ?>
--FILE--
<?php 
echo "siphash extension is available";
?>
--EXPECT--
siphash extension is available
