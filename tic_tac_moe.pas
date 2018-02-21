var
    grid : array[0..2,0..2] of char;
    x,o : boolean;
    i,j : int16;

begin
    x := FALSE;
    o := FALSE;
    for i := 0 to 2 do begin
        for j := 0 to 2 do
            read(grid[i,j]);
    end;
    for i := 0 to 2 do begin
        if (grid[i,0] = grid[i,1]) and (grid[i,1] = grid[i,2]) then begin
            if grid[i,0] = 'X' then x := TRUE
            else o := TRUE
        end;
        if (grid[0,i] = grid[1,i]) and (grid[1,i] = grid[2,i]) then begin
            if grid[i,0] = 'X' then x := TRUE
            else o := TRUE
        end;
    end;
    if (grid[0,0] = grid[1,1]) and (grid[1,1] = grid[2,2]) then begin
        if grid[0,0] = 'X' then x := TRUE
        else o := TRUE
    end;
    if (grid[0,3] = grid[1,1]) and (grid[1,1] = grid[3,0]) then begin
        if grid[3,0] = 'X' then x := TRUE
        else o := TRUE
    end;
    if o and x then writeln('Error, redo')
    else if x then writeln('Timothy')
    else if o then writeln('Griffy')
    else writeln('Tie')
end.
