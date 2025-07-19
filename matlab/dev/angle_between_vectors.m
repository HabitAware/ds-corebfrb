function angle_deg = angle_between_vectors(g1, g2)
% g1 and g2: 3-element normalized vectors
% angle_deg: angle between vectors in degrees

    dot_product = dot(g1, g2);
    dot_product = min(max(dot_product, -1.0), 1.0); % Clamp for acos safety
    angle_deg = acosd(dot_product);
end
