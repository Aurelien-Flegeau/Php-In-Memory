<?php

include('mem.php');

echo $data->getData();

echo '<br/>';
$data->setData(2);
echo $data->getData();

?>
