<?php
	/*
		--- PHP In Memory ---
		
			Demo file
	*/

	// PhpInMemory library instance
	include 'php_in_memory.php';

	// At object initialization
	// Should print "PhpInMemory"
	echo $data->get() . '<br />';

	// Put datas
	$data->set("Hello World !");

	// Should print "Hello World !"
	echo $data->get() . '<br />';
?>

