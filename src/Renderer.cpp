#include "Renderer.h"

void Renderer::renderModel(const Model& model) const
{
    glBindVertexArray(model.getVAO());
    glDrawElements(GL_TRIANGLES, model.getIndices().size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
