<?php
$servername = "localhost";
$username = "root";
$password = "";
$dbname = "shopping_cart";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$data = json_decode(file_get_contents('php://input'), true);
$cartID = $data['cartID'];
$newQuantity = $data['newQuantity'];

if ($newQuantity <= 0) {
    $sql = "DELETE FROM cart_items WHERE cartID = $cartID";
} else {
    $sql = "UPDATE cart_items SET cartQuantity = $newQuantity WHERE cartID = $cartID";
}

if ($conn->query($sql) === TRUE) {
    echo "Record updated successfully";
} else {
    echo "Error updating record: " . $conn->error;
}

$conn->close();
?>
