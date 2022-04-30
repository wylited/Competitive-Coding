use std::fs;

struct Player {
    pos: i32,
    roll: i32,
    moves: i32,
}

fn main(){
    // Open the file.
    let data = fs::read_to_string("/home/wylited/Documents/coding/Competitive Programming/codingquest/snl.txt").expect("Something went wrong reading the file");
    let mut p1 = Player {pos: 0, roll: 0, moves: 0};
    let mut p2 = Player {pos: 0, roll: 0, moves: 0};

    let mut board: Vec<Vec<i32>> = vec![vec![0; 20]; 20];
    let mut rolls: Vec<i32> = vec![0; 2];
    let size = 19; 
    for (i, lines) in data.lines().enumerate(){
        if i < 20 {
            let mut j = 0;
            while j <= size {
                board[i][j] = lines.split(" ").nth(j as usize).map(|x| x.parse::<i32>().unwrap()).unwrap();
                j += 1;
            }
            // reverse the order if its an even row numer.
            if i % 2 == 0 { board[i].reverse(); }
            board.reverse();
        } else {
            // The first value in the line is p2's roll while the second value is p2's roll.
            rolls = lines.split(" ").map(|x| x.parse::<i32>().unwrap()).collect::<Vec<i32>>();
            p1.roll = rolls[0]; p2.roll = rolls[1];
            p1.moves += 1; p2.moves += 1;
            // Update pos based on the roll
            p1.pos += p1.roll; p2.pos += p2.roll;
            // recursively update the pos if the players pos is on a tile thats value is not 0.
            while board[(p1.pos / 20) as usize][(p1.pos % 20) as usize] != 0 {
                p1.pos += board[p1.pos as usize][p1.pos as usize];
            }
            while board[(p2.pos / 20) as usize][(p2.pos % 20) as usize] != 0 {
                p2.pos += board[p2.pos as usize][p2.pos as usize];
            }
            
            println!("{}: {}, {}: {}", p2.moves, p2.pos, p2.moves, p2.pos);
        }
    }
}