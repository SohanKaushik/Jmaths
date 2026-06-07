#include "Graphs.h"

jmaths::scene::Graphs::Graphs() {

}

jmaths::scene::Graphs::Graphs(std::vector<glm::vec3> points) {
	feed_vert(points, rdrtype::CONNECT_LINES);
}
