g1 = [0; 0; 1];
g2 = [0; 1; 0];

expected = 90;
angle = angle_between_vectors(g1, g2);
assert(abs(angle - expected) < 1e-5);
disp('MATLAB prototype test passed.');
