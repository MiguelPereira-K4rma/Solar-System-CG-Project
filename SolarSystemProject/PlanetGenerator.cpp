#include <vector>
#include <cstdio>
#include <cmath> // For trigonometric functions
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

void generateSphere(float radius, int numSlices, int numStacks, std::vector<glm::vec3>& out_vertices, std::vector<glm::vec2>& out_uvs, std::vector<glm::vec3>& out_normals) {
    for (int i = 0; i <= numStacks; ++i) {
        float phi = glm::pi<float>() * static_cast<float>(i) / static_cast<float>(numStacks);
        for (int j = 0; j <= numSlices; ++j) {
            float theta = 2.0f * glm::pi<float>() * static_cast<float>(j) / static_cast<float>(numSlices);

            float x = radius * std::sin(phi) * std::cos(theta);
            float y = radius * std::cos(phi);
            float z = radius * std::sin(phi) * std::sin(theta);

            glm::vec3 vertex(x, y, z);
            glm::vec2 uv(static_cast<float>(j) / static_cast<float>(numSlices), static_cast<float>(i) / static_cast<float>(numStacks));
            glm::vec3 normal = glm::normalize(vertex);

            out_vertices.push_back(vertex);
            out_uvs.push_back(uv);
            out_normals.push_back(normal);
        }
    }

    for (int i = 0; i < numStacks; ++i) {
        for (int j = 0; j < numSlices; ++j) {
            int idx1 = i * (numSlices + 1) + j;
            int idx2 = idx1 + 1;
            int idx3 = (i + 1) * (numSlices + 1) + j;
            int idx4 = idx3 + 1;

            // Triangle 1
            out_vertices.push_back(out_vertices[idx1]);
            out_uvs.push_back(out_uvs[idx1]);
            out_normals.push_back(out_normals[idx1]);

            out_vertices.push_back(out_vertices[idx2]);
            out_uvs.push_back(out_uvs[idx2]);
            out_normals.push_back(out_normals[idx2]);

            out_vertices.push_back(out_vertices[idx3]);
            out_uvs.push_back(out_uvs[idx3]);
            out_normals.push_back(out_normals[idx3]);

            // Triangle 2
            out_vertices.push_back(out_vertices[idx3]);
            out_uvs.push_back(out_uvs[idx3]);
            out_normals.push_back(out_normals[idx3]);

            out_vertices.push_back(out_vertices[idx2]);
            out_uvs.push_back(out_uvs[idx2]);
            out_normals.push_back(out_normals[idx2]);

            out_vertices.push_back(out_vertices[idx4]);
            out_uvs.push_back(out_uvs[idx4]);
            out_normals.push_back(out_normals[idx4]);
        }
    }
}
