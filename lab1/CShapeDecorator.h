class CShapeDecorator : public sf::Shape
{
public:
    CShapeDecorator(std::shared_ptr<sf::Shape> shape);

private:
    std::shared_ptr<sf::Shape> m_shape;
};

