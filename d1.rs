use std::io::prelude::*;
use std::io::BufReader;
use std::fs::File;

fn main() -> std::io::Result<()> {
    let f = File::open("ba.txt")?;
    let mut reader = BufReader::new(f);
    while true {
        let mut line = String::new();
        let len = reader.read_line(&mut line)?;
        if len == 0 {
            break;
        }
    }
    Ok(())
}

fn moulinette() -> {
    
}