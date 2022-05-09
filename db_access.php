<?php


$servername = "localhost";
$username = "root";
$password = "";
$dbname = "rfid_counter";



// Create connection
$conn = mysqli_connect($servername, $username, $password, $dbname);
// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}else{
    // echo "<script>console.log('DB connected!' );</script>";
}
?>