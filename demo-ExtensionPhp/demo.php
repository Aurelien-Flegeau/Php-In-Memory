<?php
	include 'php_in_memory.php';

	$data->set(file_get_contents('http://www.esgi.fr'));

	echo $data->get();