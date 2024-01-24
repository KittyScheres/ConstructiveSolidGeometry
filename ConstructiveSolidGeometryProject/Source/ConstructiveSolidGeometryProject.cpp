/*******************************************************************************************
*
*   raylib example - procedural mesh generation
*
*   Example originally created with raylib 1.8, last time updated with raylib 4.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2017-2024 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "raymath.h"
#include "Primitives/Meshes/AABBMesh.h"

#define NUM_MODELS  2

static Mesh GetMeshFromAABB(Vector3 max, Vector3 min);

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [models] example - mesh generation");

    Model models[NUM_MODELS] = { 0 };

    models[0] = LoadModelFromMesh(GetMeshFromAABB(Vector3(-2.f, -1.f, -2.f), Vector3(2.f, 1.f, 2.f)));
    models[1] = LoadModelFromMesh(GetMeshFromAABB(Vector3(-1.f, -2.f, -1.f), Vector3(1.f, 2.f, 1.f)));

    // Define the camera to look into our 3d world
    Camera camera = { { 5.0f, 5.0f, 5.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };

    // Model drawing position
    Vector3 position = { 0.0f, 0.0f, 0.0f };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera, CAMERA_ORBITAL);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);

        DrawModelWires(models[0], position, 1.0f, RED);
        DrawModelWires(models[1], position, 1.0f, YELLOW);

        EndMode3D();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // Unload models data (GPU VRAM)
    UnloadModel(models[0]);
    UnloadModel(models[1]);

    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

static Mesh GetMeshFromAABB(Vector3 min, Vector3 max) {
    CSG::AABBMesh AABB = CSG::AABBMesh({ min, max });

    Mesh mesh = { 0 };
    for (const CSG::Face& face : AABB.m_faces) {
        mesh.triangleCount += face.m_triangles.size();
        mesh.vertexCount += face.m_vertices.size();
    }

    mesh.vertices = (float*)MemAlloc(mesh.vertexCount * 3 * sizeof(float));
    mesh.indices = (unsigned short*)MemAlloc(mesh.triangleCount * 3 * sizeof(unsigned short));

    uint32_t vertexCount = 0;
    uint32_t triangleCount = 0;
    for (const CSG::Face& face : AABB.m_faces) {
        for (const CSG::Triangle& triangle : face.m_triangles) {
            mesh.indices[triangleCount * 3] = triangle.m_indices[0] + vertexCount;
            mesh.indices[(triangleCount * 3) + 1] = triangle.m_indices[1] + vertexCount;
            mesh.indices[(triangleCount * 3) + 2] = triangle.m_indices[2] + vertexCount;
            triangleCount++;
        }

        for (const CSG::Vertex& vertex : face.m_vertices) {
            mesh.vertices[vertexCount * 3] = vertex.m_position.x;
            mesh.vertices[(vertexCount * 3) + 1] = vertex.m_position.y;
            mesh.vertices[(vertexCount * 3) + 2] = vertex.m_position.z;
            vertexCount++;
        }
    }
    
    UploadMesh(&mesh, false);
    return mesh;
}