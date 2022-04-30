use std::{fs, collections::HashMap};
use std::io::Write;

enum Direction {
    CENTER,
    RIGHT,
    LEFT,
    UP,
    DOWN,
}

fn recursivecheckchunk(x: usize, y: usize, space: [[Option<i32>; 100]; 100], checked: &mut HashMap<(usize, usize), i32>, direction: Direction) -> (HashMap<(usize, usize), i32>, Vec<(usize, usize)>) {
    let mut group: Vec<(usize, usize)> = Vec::new(); 
    // If a chunk has an asteriod recursively iterate through its nearby chunks.

    // Check if x or y is out of bounds. if so return the group.
    if x >= 100 || y >= 100 {
        return (checked.clone(), group);
    }

    if space[x][y].unwrap_or_default() == 0 {
        checked.insert((x, y), 0);
        return (checked.clone(), group);
    }
    
    // If the chunk has already been checked skip it
    if checked.contains_key(&(x, y)) {
        return (checked.clone(), group);
    }
    
    // Check the chunk to the right left up and down except from the direction it came from.
    match direction {
        Direction::CENTER => {
            if y < 99 {
                if space[x][y+1].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                checked.insert((x, y+1), space[x][y+1].unwrap_or_default());
                group.push((x, y+1));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::LEFT);
            }
            // Check the chunk to the left.
            if y > 0 {
                if space[x][y-1].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                print!(" checking {} {}     ", x, y);
                checked.insert((x, y-1), space[x][y-1].unwrap_or_default());
                group.push((x, y-1));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::RIGHT);
            }
            // Check the chunk above.
            if x > 0 {
                if space[x-1][y].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                checked.insert((x-1, y), space[x-1][y].unwrap_or_default());
                group.push((x-1, y));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::DOWN);
            }
            // Check the chunk below.
            if x < 99 {
                if space[x+1][y].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                checked.insert((x+1, y), space[x+1][y].unwrap_or_default());
                group.push((x+1, y));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::UP);
            } else {
                return (checked.clone(), group);
            }
        },
        Direction::RIGHT => {
            // Check the chunk to the left.
            if y > 0 {
                if space[x][y-1].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                print!(" checking {} {}     ", x, y);
                checked.insert((x, y-1), space[x][y-1].unwrap_or_default());
                group.push((x, y-1));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::RIGHT);
            }
            // Check the chunk above.
            if x > 0 {
                if space[x-1][y].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                checked.insert((x-1, y), space[x-1][y].unwrap_or_default());
                group.push((x-1, y));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::DOWN);
            }
            // Check the chunk below.
            if x < 99 {
                if space[x+1][y].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                checked.insert((x+1, y), space[x+1][y].unwrap_or_default());
                group.push((x+1, y));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::UP);
            } else {
                return (checked.clone(), group);
            }
        },
        Direction::LEFT => {
            if y < 99 {
                if space[x][y+1].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                checked.insert((x, y+1), space[x][y+1].unwrap_or_default());
                group.push((x, y+1));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::LEFT);
            }
            // Check the chunk above.
            if x > 0 {
                if space[x-1][y].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                checked.insert((x-1, y), space[x-1][y].unwrap_or_default());
                group.push((x-1, y));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::DOWN);
            }
            // Check the chunk below.
            if x < 99 {
                if space[x+1][y].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                checked.insert((x+1, y), space[x+1][y].unwrap_or_default());
                group.push((x+1, y));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::UP);
            } else {
                return (checked.clone(), group);
            }
        },
        Direction::UP => {
            if y < 99 {
                if space[x][y+1].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                checked.insert((x, y+1), space[x][y+1].unwrap_or_default());
                group.push((x, y+1));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::LEFT);
            }
            // Check the chunk to the left.
            if y > 0 {
                if space[x][y-1].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                print!(" checking {} {}     ", x, y);
                checked.insert((x, y-1), space[x][y-1].unwrap_or_default());
                group.push((x, y-1));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::RIGHT);
            }
            // Check the chunk below.
            if x < 99 {
                if space[x+1][y].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                checked.insert((x+1, y), space[x+1][y].unwrap_or_default());
                group.push((x+1, y));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::UP);
            } else {
                return (checked.clone(), group);
            }
        },
        Direction::DOWN => {
            if y < 99 {
                if space[x][y+1].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                checked.insert((x, y+1), space[x][y+1].unwrap_or_default());
                group.push((x, y+1));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::LEFT);
            }
            // Check the chunk to the left.
            if y > 0 {
                if space[x][y-1].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                print!(" checking {} {}     ", x, y);
                checked.insert((x, y-1), space[x][y-1].unwrap_or_default());
                group.push((x, y-1));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::RIGHT);
            }
            // Check the chunk above.
            if x > 0 {
                if space[x-1][y].unwrap_or_default() == 0 {
                    return (checked.clone(), group);
                }
                checked.insert((x-1, y), space[x-1][y].unwrap_or_default());
                group.push((x-1, y));
                // Recursively call on itself
                recursivecheckchunk(x+1, y, space, checked, Direction::DOWN);
            } else {
                return (checked.clone(), group);
            }
        },
    }
    return (checked.clone(), group);
}

fn main() {
    //     You get a call to come up to the bridge to assist with a surveying task. It seems your ship is passing through an asteroid belt of some form. The onboard space geologist is quite excited by the find and wants to catalogue as much as possible while they are in the area.

    // The ship has sensors that have taken a detailed reading of the nearby environment, measuring the size and density of the various asteroids and minor planets in the vicinity. You have been tasked with calculating the mean mass of the asteroids and other bodies in the system.

    // A 0 denotes empty space, where as a number 1 through 9 indicates the density level of an object occupying a portion of space.
    // any individual asteroid will be represented through vertically or horizontally adjacent grid squares, never diagonal

    // A 100 by 100 square grid is given to you which contains the locations of nearby asteroids.
    let data = fs::read_to_string("/home/wylited/Documents/coding/Competitive Programming/codingquest/saab.txt").expect("Something went wrong reading the file");
    let mut space: [[Option<i32>; 100]; 100] = [[Some(0); 100] ; 100];
    for (i, val) in data.lines().enumerate() {
        let mut j = 0;
        while j < 100 {
            space[i][j] = Some(val.split(" ").nth(j as usize).map(|x| x.parse::<i32>().unwrap()).unwrap_or_default());
            j += 1;
        }
    }
    // Create a hashmap of already checked chunks.
    let mut checked: HashMap<(usize, usize), i32> = HashMap::new();

    // Create a vector of asteriod chunks that are connected
    let mut chunks: HashMap<i32, Vec<(usize, usize)>> = HashMap::new();
    let mut checkedtot: i32 = 0;

    // Iterate through the chunks and find the total number of asteroids 
    for i in 0..100 {
        for j in 0..100 {
            checkedtot += 1;
            // Check if the chunk has already been checked.
            if checked.contains_key(&(i, j)) {
                continue;
            }
            // Ignore if the chunk is == 0 
            if space[i][j].unwrap_or_default() == 0 {
                chunks.insert(((i * 20) + j).try_into().unwrap(), vec![(i, j)]);
                checked.insert((i, j), space[i][j].unwrap_or_default());
                continue;
            }
            // Add this key to the checked hashmap
            checked.insert((i, j), space[i][j].unwrap_or_default());
            let mut group: Vec<(usize, usize)> = Vec::new();

            // Use the recusrivecheckchunk to find all of the nearby asteriod chunks in this group.
            let (checked, group) = recursivecheckchunk(i, j, space, &mut checked, Direction::CENTER);

            print!("asteriod: {} {} ", i, j);
            // Add this chunk to the hashmap its key being i*20 + j
            chunks.insert(((i * 20) + j).try_into().unwrap(), group);
        }
    }

    println!(" ");

    // Make sure every single chunk has been checked.
    for i in 0..100 {
        for j in 0..100 {
            if !checked.contains_key(&(i, j)) {
                print!("missed: {} {} ", i, j);
            }
        }
    }
    // print the total number of chunks
    println!("{}", chunks.len());
    // print the total number of asteriods
    let mut total: i32 = 0;
    for i in 0..100 {
        for j in 0..100 {
            if space[i][j].unwrap_or_default() != 0 {
                total += space[i][j].unwrap();
            }
        }
    }
    println!("{}", total);
    println!("{}", chunks.keys().len());
    println!("{}", checkedtot);
}