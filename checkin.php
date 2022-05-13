<?php

include 'db_access.php';
$response = "";
$status = "";

$date = new DateTime("now", new DateTimeZone('Asia/Makassar') );
$waktu = $date->format('Y-m-d H:i:s');

 if(isset($_GET['card'])) {
    $card_id = $_GET['card'];    
    $check_in = mysqli_query($conn,"SELECT * FROM rfid_checkin WHERE id_card='" .$card_id."'");
    if($check_in){
        if (mysqli_num_rows($check_in) > 0) {
            //id sudah hadir
          
            $sql = "DELETE FROM rfid_checkin WHERE id_card='" .$card_id. "'";
            if (!mysqli_query($conn,$sql)){                           
                $response = 'ERROR KELUAR';
            }else{               
                $response = 'KELUAR';
            }
            $status = "keluar";
        }else{
            //id belum hadir
           
            $sql = "INSERT INTO rfid_checkin(id_card,waktu) VALUES ('$card_id','$waktu')";
            
            if (!mysqli_query($conn,$sql)){            
               
                $response = 'ERROR MASUK';
            }else{               
                $response = 'MASUK';
            }
            $status = "masuk";
        }
    }else{
        $status = 'Error CHECKIN';
    }
     
    $sql = "INSERT INTO rfid_log(id_card,waktu, stat) VALUES ('$card_id','$waktu','$status')";
            
    if (!mysqli_query($conn,$sql)){            
       
        $response = 'ERROR LOG';
    }


    echo 'RES:'.$response;
}
?>