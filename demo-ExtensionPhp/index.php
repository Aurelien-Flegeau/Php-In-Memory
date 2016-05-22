<?php
	/*
		--- PHP In Memory ---
		
			Demo file
	*/

	// PhpInMemory library instance
	include('php_in_memory.php');

	// At object initialization
	// Should print "PhpInMemory"
	echo $data->getData() . '<br/>';

	// Put datas
	$data->setData("Hello World !");
	
	// Should print "Hello World !"
	echo $data->getData() . '<br/>';
?>
