--TEST--
Check sip_hash()
--SKIPIF--
<?php if (!extension_loaded("siphash")) print "skip"; ?>
--FILE--
<?php 
echo base64_encode(sip_hash('CAFEBABEDEADBEEF', 'message'))
?>
--EXPECT--
kArt90NAHXQ=
