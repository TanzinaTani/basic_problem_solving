<!-- check the similarity of the word content from two files using Jaccard similarity. -->

<?php 
$file1 = fopen('one1.txt','r');
while(!feof($file1)){
echo fgets($file1);
echo "<br>";
}
echo "<br><br><br>";

$file2 = fopen('two2.txt','r');
while(!feof($file2)){
echo fgets($file2);
echo "<br>";
}

$text1 = file_get_contents('one1.txt');
$text2 = file_get_contents('two2.txt');

$textf1 = preg_replace("/[^A-Za-z0-9\-\s]/","", $text1);

echo "<br>";

$textf2 = preg_replace("/[^A-Za-z0-9\-\s]/","", $text2);
echo "<br>";

$textf1 = strtolower($textf1);
$textf2 = strtolower($textf2);
$test1 = implode(' ', array_unique(explode(' ', $textf1)));
$test2 = implode(' ', array_unique(explode(' ', $textf2)));


$splitted_text1 = explode(" ", $test1);
$splitted_text2 = explode(" ", $test2);

$result1 = array_map('trim', $splitted_text1);
$result2 = array_map('trim', $splitted_text2);
$result = array_filter($splitted_text1);                 

echo "<br>";
$results = array_filter($splitted_text2);                 

$length1 = count($result);
$length2 = count($results);

echo "<b>preprocess first text: </b><br>";
for ($i=0; $i <$length1 ; $i++) { 
   echo "$result1[$i] ";
}
echo "<br><br>";
echo "<b>preprocess 2nd text: </b><br>";
for ($i=0; $i <$length2 ; $i++) { 
   echo "$result2[$i] ";
}

echo "<br><br><br><br>First Text Length: $length1<br>";
echo "<br>Second Text Length: $length2<br>";


$final = array();
$count=0; 
if ($length2>=$length1) {
 
for($i = 0; $i < $length2; $i++) {  

          $word = array(); 
    for($j = 0; $j < $length1; $j++) {  

        if($result2[$i] == $result1[$j]) {  

            $word[$i]  = $result2[$i]; 
        }   
    }  

     if(!empty($word)){

          $final[$i] = $word[$i];
          $count++;
        
    }
     
  }
}
elseif ($length1>$length2) {
    for($i = 0; $i < $length1; $i++) {  

          $word = array(); 

    for($j = 0; $j < $length2; $j++) {  
        if($result1[$i] == $result2[$j]) {  
            $word[$i]  = $result1[$i]; 

        }  
    }  
    
       if(!empty($word)){

          $final[$i] = $word[$i];
          $count++;  
      
    }
     
  }
}

       echo "<br>Common words in two files: <br>";
       echo join(" ",$final);
      $file = 'output.txt';
      $finalresult = join(" ",$final);
      file_put_contents($file, $finalresult);
       
       $total = $length1 +$length2;
       echo("<br><br><br> file1's unique words intersect file2's unique words: ");
       echo "$count";
       echo("<br> file1's unique words union file2's unique words: ");
       echo "$total";
       echo "<br> Jaccard coefficient: ";
        $Jaccard = $count / $total;
       echo "$Jaccard<br><br>";

 ?>