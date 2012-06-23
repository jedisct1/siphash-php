--TEST--
Check siphash32()
--SKIPIF--
<?php if (!extension_loaded("siphash")) print "skip"; ?>
--FILE--
<?php 
echo dechex(sip_hash32('CAFEBABEDEADBEEF', 'message'))
?>
--EXPECT--
f7ed0a90
