<?php

include('mem.php');

echo $data->getData(); //affiche 0

echo '<br/>';
$data->setData(2);	//met 2
echo $data->getData(); //affiche 2

?>
