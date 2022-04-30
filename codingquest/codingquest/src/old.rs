use std::fs;

fn main(){
    let data = fs::read_to_string("/home/wylited/Documents/coding/Competitive Programming/codingquest/lit.txt").expect("Something went wrong reading the file");
    let mut msg = [[0; 11]; 19];
    // Loop through the data and assign it to the msg array
    for (i, val) in data.lines().enumerate() {
        let mut j = 0;
        while j < 11 {
            msg[i][j] = i32::from_str_radix(val.split(" ").nth(j as usize).unwrap(), 16).unwrap_or_default();
            j += 1;
        }
    }
    // pretty print the msg array
    for i in 0..19 {
        for j in 0..11 {
            print!("{} ", msg[i][j]);
        }
        println!("");
    }

    // Calculate which row has the erroneous byte value
    let mut row = 0;
    // Find the row with the non equal checksum to the rowsum value
    for i in 0..18 {
        println!("row: {}", i);
        println!("Checking row {}", i);
        println!("Checksum is: {}", msg[i][10]);
        println!("values are: {} {} {} {} {} {} {} {} {} {}", msg[i][0], msg[i][1], msg[i][2], msg[i][3], msg[i][4], msg[i][5], msg[i][6], msg[i][7], msg[i][8], msg[i][9]);
        if msg[i][10] != calcchecksum(&vec![msg[i][0], msg[i][1], msg[i][2], msg[i][3], msg[i][4], msg[i][5], msg[i][6], msg[i][7], msg[i][8], msg[i][9]]) {
            println!("row {} was erroneous", i);
            row = i;
            break;
        }
    }
    // Repeat for the vertical columns, where the last row is the checksum.
    let mut col = 0;
    for i in 0..10 {
        println!("col: {}", i);
        println!("Checking col {}", i);
        println!("Checksum is: {}", msg[18][i]);
        println!("values are: {} {} {} {} {} {} {} {} {} {}", msg[0][i], msg[1][i], msg[2][i], msg[3][i], msg[4][i], msg[5][i], msg[6][i], msg[7][i], msg[8][i], msg[9][i]);
        if msg[18][i] != calcchecksum(&vec![msg[0][i], msg[1][i], msg[2][i], msg[3][i], msg[4][i], msg[5][i], msg[6][i], msg[7][i], msg[8][i], msg[9][i], msg[10][i], msg[11][i], msg[12][i], msg[13][i], msg[14][i], msg[15][i], msg[16][i], msg[17][i]]) {
            println!("col {} was erroneous", i);
            col = i;
            break;
        }
    }

    println!("{} {}", row, col);
}

fn calcchecksum(val: &Vec<i32>) -> i32 {
    let mut checksum = 0;
    // Add all the values and then find the modulus when divided by 256
    for i in val {
        checksum += i;
    }
    println!("{}", checksum % 256);
    checksum % 256
}

pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut seen = HashMap::new(); let mut remaining = 0;
    for (val, i) in nums.iter().enumerate() {
        remaining = target - val as i32;
        if(seen.contains_key(&remaining)){
            return vec![seen[&remaining], *i];
        }
        seen.insert(val, *i);
    }
    return vec![0,0];
}