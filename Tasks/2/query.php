<?php
   function foo()
   {
      $host = 'localhost'; 
      $db_name = 'database'; 
      $user = 'user'; 
      $password = 'password'; 

      
      $connection = pg_connect($host, $user, $password, $db_name);

   
      $query = 'SELECT * FROM buyers';

   
      $result = pg_query($connection, $query);

   
      while($row = $result->fetch_assoc()){
         echo  $row['ID'];
         echo  ' - ';
         echo  $row['NAME'];
         echo  '<br>';
      }

   
      pg_close($connection);
   }

   foo();
?>
